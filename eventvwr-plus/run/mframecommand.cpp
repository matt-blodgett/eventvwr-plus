#include "mframecommand.h"

#include <QGridLayout>

#include <QLabel>
#include <QComboBox>


MFrameCommand::MFrameCommand(QWidget *parent) : MFrame(parent)
{
    m_lblIcon = new QLabel(this);
    m_lblInfo = new QLabel(this);
    m_lblOpen = new QLabel(this);
    m_cbxOpen = new QComboBox(this);

    QGridLayout *gridMain = new QGridLayout();
    gridMain->addWidget(m_lblIcon, 1, 0, 1, 1);
    gridMain->addWidget(m_lblInfo, 1, 1, 1, 1);
    gridMain->addWidget(m_lblOpen, 2, 0, 1, 1);
    gridMain->addWidget(m_cbxOpen, 2, 1, 1, 1);
    gridMain->setColumnStretch(1, 1);
    gridMain->setContentsMargins(5, 5, 10, 20);
    setLayout(gridMain);

    QPixmap runPixmap(":/icons/run-bg.png");
    QPixmap openPixmap(":/icons/open.png");
    m_lblIcon->setPixmap(runPixmap);
    m_lblOpen->setPixmap(openPixmap);

    m_lblInfo->setText("Type the name of a program, folder, document, or Internet resource, and Windows will open it for you.");
    m_lblInfo->setWordWrap(true);
    m_cbxOpen->setEditable(true);

    m_lblIcon->setObjectName("lblIcon");
    m_lblInfo->setObjectName("lblInfo");
    m_lblOpen->setObjectName("lblOpen");
    setObjectName("frmCommand");
}

QComboBox *MFrameCommand::cbxOpen()
{
    return m_cbxOpen;
}
