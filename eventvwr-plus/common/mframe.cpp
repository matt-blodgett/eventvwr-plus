#include "mframe.h"

#include <QStyleOption>
#include <QPainter>


MFrame::MFrame(QWidget *parent) : QWidget(parent)
{

}

void MFrame::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.initFrom(this);

    QPainter painter(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);

    QWidget::paintEvent(event);
}
