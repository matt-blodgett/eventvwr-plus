#include "mframecommand.h"

#include <QLabel>
#include <QComboBox>

#include <QGridLayout>
#include <QPainter>


MFrameCommand::MFrameCommand(QWidget *parent) : QWidget(parent)
{
    m_lblIcon = new QLabel(this);
    m_lblInfo = new QLabel(this);
    m_lblOpen = new QLabel(this);
    m_cbxOpen = new QComboBox(this);

    QGridLayout *grid_main = new QGridLayout(this);
    grid_main->addWidget(m_lblIcon, 1, 0, 1, 1);
    grid_main->addWidget(m_lblInfo, 1, 1, 1, 1);
    grid_main->addWidget(m_lblOpen, 2, 0, 1, 1);
    grid_main->addWidget(m_cbxOpen, 2, 1, 1, 1);
    grid_main->setColumnStretch(1, 1);
//    grid_main->setContentsMargins(left, top, right, bottom);
    grid_main->setContentsMargins(5, 5, 10, 10);
    grid_main->setSpacing(0);

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
    m_cbxOpen->setObjectName("cbxOpen");
    setObjectName("frmCommand");

    resize(400, 115);
}

void MFrameCommand::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.initFrom(this);

    QPainter painter(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);

    QWidget::paintEvent(event);
}
