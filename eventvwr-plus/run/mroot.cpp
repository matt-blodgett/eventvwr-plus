#include "mroot.h"

#include "mframecommand.h"
#include "mframebuttons.h"

#include <QGridLayout>

#include <QFileDialog>
#include <QPushButton>
#include <QComboBox>

#include <QFile>
#include <QDir>


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
