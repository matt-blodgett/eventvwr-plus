#ifndef MFRAMEBUTTONS_H
#define MFRAMEBUTTONS_H


#include "common/mframe.h"


QT_BEGIN_INCLUDE_NAMESPACE
class QPushButton;
QT_END_INCLUDE_NAMESPACE


class MFrameButtons : public MFrame
{
    Q_OBJECT

public:
    explicit MFrameButtons(QWidget *parent = nullptr);

public:
    QPushButton *btnOk();
    QPushButton *btnCancel();
    QPushButton *btnBrowse();

private:
    QPushButton *m_btnOk = nullptr;
    QPushButton *m_btnCancel = nullptr;
    QPushButton *m_btnBrowse = nullptr;
};


#endif
