import sys
from run.root import Root

from PyQt5.QtWidgets import QApplication


if __name__ == '__main__':
    app = QApplication([])
    root = Root()
    root.show()
    sys.exit(app.exec())
