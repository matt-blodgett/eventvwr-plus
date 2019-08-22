#ifndef MROOT_H
#define MROOT_H


#include <QMainWindow>


class MFrameCommand;


class MRoot : public QMainWindow
{
    Q_OBJECT

public:
    MRoot(QWidget *parent = nullptr);

private:
    MFrameCommand *m_frmCommand = nullptr;
};


#endif
