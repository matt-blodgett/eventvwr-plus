#include "mframebuttons.h"

#include <QGridLayout>
#include <QPushButton>

#include <QLabel>


MFrameButtons::MFrameButtons(QWidget *parent) : MFrame(parent)
{
    m_btnOk = new QPushButton(this);
    m_btnCancel = new QPushButton(this);
    m_btnBrowse = new QPushButton(this);

    QGridLayout *gridMain = new QGridLayout();
    gridMain->setColumnStretch(0, 1);
    gridMain->addWidget(m_btnOk, 0, 1, 1, 1);
    gridMain->addWidget(m_btnCancel, 0, 2, 1, 1);
    gridMain->addWidget(m_btnBrowse, 0, 3, 1, 1);
    setLayout(gridMain);

    m_btnOk->setText("OK");
    m_btnCancel->setText("Cancel");
    m_btnBrowse->setText("Browse...");
}

QPushButton *MFrameButtons::btnOk() {
    return m_btnOk;
}
QPushButton *MFrameButtons::btnCancel() {
    return m_btnCancel;
}
QPushButton *MFrameButtons::btnBrowse() {
    return m_btnBrowse;
}
