#ifndef MROOT_H
#define MROOT_H


#include <QMainWindow>


class MFrameCommand;
class MFrameButtons;


class MRoot : public QMainWindow
{
    Q_OBJECT

public:
    MRoot(QWidget *parent = nullptr);

private:
    MFrameCommand *m_frmCommand = nullptr;
    MFrameButtons *m_frmButtons = nullptr;

private slots:
    void commandTextChanged(const QString &text);
    void executeCommand();
    void browseCommands();
    void exit();
};


#endif
