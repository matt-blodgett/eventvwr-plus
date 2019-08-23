#include "mroot.h"

#include "mframecommand.h"
#include "mframebuttons.h"

#include <QGridLayout>

#include <QFileDialog>
#include <QPushButton>
#include <QComboBox>
#include <QLineEdit>

#include <QProcess>
#include <QFile>
#include <QDir>

#include <QJsonDocument>
#include <QJsonObject>


QString lookupCommand(const QString &cmd)
{
    QFile jsonFile("./commands.json");
    if (jsonFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QJsonParseError jsonError;
        QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonFile.readAll(), &jsonError);
        if (jsonError.error == QJsonParseError::NoError) {
            for (QString key : jsonDoc.object().keys()) {
                if (key == cmd) {
                    return jsonDoc[key].toString();
                }
            }
        }
    }

    if (cmd.mid(0, 3) == "cmd") {
        return "python ./cmd.py";
    }

    return cmd;
}


MRoot::MRoot(QWidget *parent) : QMainWindow(parent)
{
    Q_INIT_RESOURCE(run);

    m_frmCommand = new MFrameCommand(this);
    m_frmButtons = new MFrameButtons(this);

    QWidget *wndMain = new QWidget(this);
    QGridLayout *gridMain = new QGridLayout();
    gridMain->addWidget(m_frmCommand, 0, 0, 1, 1);
    gridMain->addWidget(m_frmButtons, 1, 0, 1, 1);
    gridMain->setContentsMargins(0, 0, 0, 0);
    wndMain->setLayout(gridMain);
    setCentralWidget(wndMain);

    setWindowTitle("Run");

    Qt::WindowFlags flags;
    flags |= Qt::Dialog;
    flags |= Qt::CustomizeWindowHint;
    flags |= Qt::WindowTitleHint;
    flags |= Qt::WindowCloseButtonHint;
    flags |= Qt::MSWindowsFixedSizeDialogHint;
    setWindowFlags(flags);

    QPixmap runPixmap(":/icons/run.png");
    setWindowIcon(QIcon(runPixmap));

    QFile qssFile(":/styles/run.qss");
    if (qssFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        setStyleSheet(qssFile.readAll());
    }

    m_frmCommand->setFixedHeight(115);
    setFixedSize(QSize(400, 175));

    m_frmButtons->btnOk()->setDisabled(true);
    connect(m_frmCommand->cbxOpen(), &QComboBox::editTextChanged, this, &MRoot::commandTextChanged);
    connect(m_frmCommand->cbxOpen()->lineEdit(), &QLineEdit::returnPressed, this, &MRoot::executeCommand);
    connect(m_frmButtons->btnOk(), &QPushButton::released, this, &MRoot::executeCommand);
    connect(m_frmButtons->btnCancel(), &QPushButton::released, this, &MRoot::exit);
    connect(m_frmButtons->btnBrowse(), &QPushButton::released, this, &MRoot::browseCommands);
}

void MRoot::commandTextChanged(const QString &text)
{
    m_frmButtons->btnOk()->setDisabled(text.isEmpty());
}
void MRoot::executeCommand()
{
    QString cmd = m_frmCommand->cbxOpen()->currentText();
    cmd = lookupCommand(cmd);

    if (!cmd.isEmpty()) {
        QProcess::startDetached(cmd);
    }
}
void MRoot::browseCommands()
{
    QString path = QFileDialog::getOpenFileName(this, "Browse");

    if(!path.isEmpty()) {
        QString setPath = QDir::toNativeSeparators(path);
        QString editText = "\"" + setPath + "\"";
        m_frmCommand->cbxOpen()->setEditText(editText);
    }
}
void MRoot::exit()
{
    window()->close();
}
