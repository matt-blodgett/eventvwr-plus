from PyQt5 import QtWidgets


class Root(QtWidgets.QMainWindow):

    def __init__(self, *args):
        super().__init__(*args)

        self.resize(200, 200)
