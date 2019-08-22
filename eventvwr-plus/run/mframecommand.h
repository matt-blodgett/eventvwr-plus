#ifndef MFRAMECOMMAND_H
#define MFRAMECOMMAND_H


#include "common/mframe.h"


QT_BEGIN_INCLUDE_NAMESPACE
class QLabel;
class QComboBox;
QT_END_INCLUDE_NAMESPACE


class MFrameCommand : public MFrame
{
    Q_OBJECT

public:
    explicit MFrameCommand(QWidget *parent = nullptr);

public:
    QComboBox *cbxOpen();

private:
    QLabel *m_lblIcon = nullptr;
    QLabel *m_lblInfo = nullptr;
    QLabel *m_lblOpen = nullptr;
    QComboBox *m_cbxOpen = nullptr;
};


#endif
