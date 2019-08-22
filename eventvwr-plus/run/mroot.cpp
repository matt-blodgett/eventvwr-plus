#include "mroot.h"

#include "mframecommand.h"

#include <QGridLayout>

#include <QFile>


MRoot::MRoot(QWidget *parent) : QMainWindow(parent)
{
    Q_INIT_RESOURCE(run);

    m_frmCommand = new MFrameCommand(this);

    QGridLayout *grid_main = new QGridLayout();
    grid_main->addWidget(m_frmCommand, 0, 0, 1, 1);
    grid_main->setRowStretch(1, 1);

    resize(400, 175);

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
}
