#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    resize(400, 175);
    setStyleSheet("QWidget {font-family: \"Segoe UI\"; font-size: 12px;}");

    setWindowTitle("Run");

    Qt::WindowFlags flags;
    flags |= Qt::Dialog;
    flags |= Qt::CustomizeWindowHint;
    flags |= Qt::WindowTitleHint;
    flags |= Qt::WindowCloseButtonHint;
    flags |= Qt::MSWindowsFixedSizeDialogHint;
    setWindowFlags(flags);

    QPixmap runPixmap("./assets/run.png");
    setWindowIcon(QIcon(runPixmap));
}




//        frm_open = OpenFrame(self)

//        grid_main = QtWidgets.QGridLayout(self)
//        grid_main.addWidget(frm_open, 0, 0, 1, 1)




//ss_openframe = """
//QWidget {
//    background-color: #FFFFFF;
//}

//QComboBox {
//    border: 1px solid #AAAAAA;
//    padding: 2px;
//    margin-left: 10px;
//    margin-right: 10px;
//}

//QComboBox::drop-down {
//    subcontrol-origin: padding;
//    subcontrol-position: top right;
//    width: 15px;
//    border-left-width: 1px;
//    border-left-color: #888888;
//    border-left-style: solid;
//}

//QComboBox QAbstractItemView {
//    background: #222222;
//    color: #FFFFFF;
//    border: 1px solid #696969;
//    margin-top: 0px;
//    padding-bottom: 0px;
//}

//QLabel#lblIcon {
//    margin-left: 10px;
//}
//QLabel#lblOpen {
//    margin-left: 10px;
//}
//QLabel#lblInfo {
//    margin-left: 10px;
//}
//"""


//class OpenFrame(QtWidgets.QFrame):

//    def __init__(self, *args):
//        super().__init__(*args)

//        self.setStyleSheet(ss_openframe)

//        self.resize(400, 115)

//        lbl_icon = QtWidgets.QLabel(self)
//        lbl_info = QtWidgets.QLabel(self)
//        lbl_open = QtWidgets.QLabel(self)
//        cbx_open = QtWidgets.QComboBox(self)

//        grid_main = QtWidgets.QGridLayout(self)
//        grid_main.addWidget(lbl_icon, 1, 0, 1, 1)
//        grid_main.addWidget(lbl_info, 1, 1, 1, 1)
//        grid_main.addWidget(lbl_open, 2, 0, 1, 1)
//        grid_main.addWidget(cbx_open, 2, 1, 1, 1)
//        grid_main.setColumnStretch(1, 1)

//        grid_main.setRowStretch(0, 1)
//        grid_main.setRowStretch(3, 1)

//        grid_main.setContentsMargins(0, 0, 0, 0)
//        grid_main.setSpacing(0)

//        run_pixmap = QtGui.QPixmap('./assets/run.png')
//        lbl_icon.setPixmap(run_pixmap)

//        lbl_info.setText('Type the name of a program, folder, document, or Internet resource, and Windows will open it for you.')
//        lbl_info.setWordWrap(True)

//        lbl_open.setText('&Open:')
//        cbx_open.addItems([''])
//        cbx_open.setCurrentText('')
//        cbx_open.setEditable(True)
//        # cbx_open.view().window().setWindowFlags(Qt.Popup | Qt.FramelessWindowHint | Qt.NoDropShadowWindowHint)
//        lbl_open.setBuddy(cbx_open)

//        lbl_icon.setObjectName('lblIcon')
//        lbl_info.setObjectName('lblInfo')
//        cbx_open.setObjectName('cbxOpen')
//        lbl_open.setObjectName('lblOpen')

