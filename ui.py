# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'rsa-ui.ui'
#
# Created by: PyQt5 UI code generator 5.9.2
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(960, 720)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Fixed, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(MainWindow.sizePolicy().hasHeightForWidth())
        MainWindow.setSizePolicy(sizePolicy)
        MainWindow.setMinimumSize(QtCore.QSize(960, 720))
        MainWindow.setMaximumSize(QtCore.QSize(960, 720))
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.tabWidget = QtWidgets.QTabWidget(self.centralwidget)
        self.tabWidget.setGeometry(QtCore.QRect(-1, -21, 961, 711))
        self.tabWidget.setObjectName("tabWidget")
        self.encryption = QtWidgets.QWidget()
        self.encryption.setObjectName("encryption")
        self.verticalLayoutWidget = QtWidgets.QWidget(self.encryption)
        self.verticalLayoutWidget.setGeometry(QtCore.QRect(-1, 9, 961, 671))
        self.verticalLayoutWidget.setObjectName("verticalLayoutWidget")
        self.verticalLayout = QtWidgets.QVBoxLayout(self.verticalLayoutWidget)
        self.verticalLayout.setContentsMargins(0, 0, 0, 0)
        self.verticalLayout.setObjectName("verticalLayout")
        self.horizontalLayout_3 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_3.setObjectName("horizontalLayout_3")
        self.verticalLayout_2 = QtWidgets.QVBoxLayout()
        self.verticalLayout_2.setObjectName("verticalLayout_2")
        self.horizontalLayout_8 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_8.setObjectName("horizontalLayout_8")
        self.label = QtWidgets.QLabel(self.verticalLayoutWidget)
        self.label.setObjectName("label")
        self.horizontalLayout_8.addWidget(self.label)
        self.comboBox = QtWidgets.QComboBox(self.verticalLayoutWidget)
        self.comboBox.setObjectName("comboBox")
        self.comboBox.addItem("")
        self.comboBox.addItem("")
        self.comboBox.addItem("")
        self.comboBox.addItem("")
        self.horizontalLayout_8.addWidget(self.comboBox)
        self.btn_gen = QtWidgets.QPushButton(self.verticalLayoutWidget)
        self.btn_gen.setObjectName("btn_gen")
        self.horizontalLayout_8.addWidget(self.btn_gen)
        self.gen_time = QtWidgets.QLabel(self.verticalLayoutWidget)
        self.gen_time.setAlignment(QtCore.Qt.AlignCenter)
        self.gen_time.setObjectName("gen_time")
        self.horizontalLayout_8.addWidget(self.gen_time)
        self.horizontalLayout_8.setStretch(0, 1)
        self.horizontalLayout_8.setStretch(1, 1)
        self.horizontalLayout_8.setStretch(2, 10)
        self.horizontalLayout_8.setStretch(3, 5)
        self.verticalLayout_2.addLayout(self.horizontalLayout_8)
        self.groupBox_2 = QtWidgets.QGroupBox(self.verticalLayoutWidget)
        self.groupBox_2.setObjectName("groupBox_2")
        self.groupBox_3 = QtWidgets.QGroupBox(self.groupBox_2)
        self.groupBox_3.setGeometry(QtCore.QRect(20, 20, 211, 231))
        self.groupBox_3.setObjectName("groupBox_3")
        self.val_N_pub = QtWidgets.QTextEdit(self.groupBox_3)
        self.val_N_pub.setGeometry(QtCore.QRect(0, 20, 211, 201))
        self.val_N_pub.setObjectName("val_N_pub")
        self.groupBox_4 = QtWidgets.QGroupBox(self.groupBox_2)
        self.groupBox_4.setGeometry(QtCore.QRect(250, 20, 211, 221))
        self.groupBox_4.setObjectName("groupBox_4")
        self.val_E = QtWidgets.QTextEdit(self.groupBox_4)
        self.val_E.setGeometry(QtCore.QRect(0, 20, 211, 201))
        self.val_E.setObjectName("val_E")
        self.verticalLayout_2.addWidget(self.groupBox_2)
        self.verticalLayout_2.setStretch(0, 1)
        self.verticalLayout_2.setStretch(1, 5)
        self.horizontalLayout_3.addLayout(self.verticalLayout_2)
        self.groupBox = QtWidgets.QGroupBox(self.verticalLayoutWidget)
        self.groupBox.setObjectName("groupBox")
        self.verticalLayoutWidget_3 = QtWidgets.QWidget(self.groupBox)
        self.verticalLayoutWidget_3.setGeometry(QtCore.QRect(0, 20, 461, 281))
        self.verticalLayoutWidget_3.setObjectName("verticalLayoutWidget_3")
        self.verticalLayout_3 = QtWidgets.QVBoxLayout(self.verticalLayoutWidget_3)
        self.verticalLayout_3.setContentsMargins(0, 0, 0, 0)
        self.verticalLayout_3.setObjectName("verticalLayout_3")
        self.message_input = QtWidgets.QTextEdit(self.verticalLayoutWidget_3)
        self.message_input.setObjectName("message_input")
        self.verticalLayout_3.addWidget(self.message_input)
        self.horizontalLayout_10 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_10.setObjectName("horizontalLayout_10")
        self.en_time = QtWidgets.QLabel(self.verticalLayoutWidget_3)
        self.en_time.setLayoutDirection(QtCore.Qt.LeftToRight)
        self.en_time.setAlignment(QtCore.Qt.AlignCenter)
        self.en_time.setObjectName("en_time")
        self.horizontalLayout_10.addWidget(self.en_time)
        self.btn_en = QtWidgets.QPushButton(self.verticalLayoutWidget_3)
        self.btn_en.setObjectName("btn_en")
        self.horizontalLayout_10.addWidget(self.btn_en)
        self.verticalLayout_3.addLayout(self.horizontalLayout_10)
        self.verticalLayout_3.setStretch(0, 10)
        self.verticalLayout_3.setStretch(1, 1)
        self.horizontalLayout_3.addWidget(self.groupBox)
        self.horizontalLayout_3.setStretch(0, 20)
        self.horizontalLayout_3.setStretch(1, 20)
        self.verticalLayout.addLayout(self.horizontalLayout_3)
        spacerItem = QtWidgets.QSpacerItem(20, 40, QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Expanding)
        self.verticalLayout.addItem(spacerItem)
        self.horizontalLayout_4 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_4.setObjectName("horizontalLayout_4")
        self.horizontalLayout_9 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_9.setObjectName("horizontalLayout_9")
        self.groupBox_6 = QtWidgets.QGroupBox(self.verticalLayoutWidget)
        self.groupBox_6.setObjectName("groupBox_6")
        self.groupBox_7 = QtWidgets.QGroupBox(self.groupBox_6)
        self.groupBox_7.setGeometry(QtCore.QRect(130, 20, 111, 291))
        self.groupBox_7.setObjectName("groupBox_7")
        self.val_D = QtWidgets.QTextEdit(self.groupBox_7)
        self.val_D.setGeometry(QtCore.QRect(0, 20, 111, 271))
        self.val_D.setObjectName("val_D")
        self.groupBox_8 = QtWidgets.QGroupBox(self.groupBox_6)
        self.groupBox_8.setGeometry(QtCore.QRect(250, 20, 111, 291))
        self.groupBox_8.setObjectName("groupBox_8")
        self.val_P = QtWidgets.QTextEdit(self.groupBox_8)
        self.val_P.setGeometry(QtCore.QRect(0, 20, 111, 271))
        self.val_P.setObjectName("val_P")
        self.groupBox_9 = QtWidgets.QGroupBox(self.groupBox_6)
        self.groupBox_9.setGeometry(QtCore.QRect(370, 20, 111, 291))
        self.groupBox_9.setObjectName("groupBox_9")
        self.val_Q = QtWidgets.QTextEdit(self.groupBox_9)
        self.val_Q.setGeometry(QtCore.QRect(0, 20, 111, 271))
        self.val_Q.setObjectName("val_Q")
        self.groupBox_5 = QtWidgets.QGroupBox(self.groupBox_6)
        self.groupBox_5.setGeometry(QtCore.QRect(490, 0, 461, 321))
        self.groupBox_5.setObjectName("groupBox_5")
        self.verticalLayoutWidget_4 = QtWidgets.QWidget(self.groupBox_5)
        self.verticalLayoutWidget_4.setGeometry(QtCore.QRect(0, 20, 461, 291))
        self.verticalLayoutWidget_4.setObjectName("verticalLayoutWidget_4")
        self.verticalLayout_4 = QtWidgets.QVBoxLayout(self.verticalLayoutWidget_4)
        self.verticalLayout_4.setContentsMargins(0, 0, 0, 0)
        self.verticalLayout_4.setObjectName("verticalLayout_4")
        self.ciphertext_input = QtWidgets.QTextEdit(self.verticalLayoutWidget_4)
        self.ciphertext_input.setObjectName("ciphertext_input")
        self.verticalLayout_4.addWidget(self.ciphertext_input)
        self.horizontalLayout_11 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_11.setObjectName("horizontalLayout_11")
        self.de_time = QtWidgets.QLabel(self.verticalLayoutWidget_4)
        self.de_time.setAlignment(QtCore.Qt.AlignCenter)
        self.de_time.setObjectName("de_time")
        self.horizontalLayout_11.addWidget(self.de_time)
        self.btn_de = QtWidgets.QPushButton(self.verticalLayoutWidget_4)
        self.btn_de.setObjectName("btn_de")
        self.horizontalLayout_11.addWidget(self.btn_de)
        self.btn_de_crt = QtWidgets.QPushButton(self.verticalLayoutWidget_4)
        self.btn_de_crt.setObjectName("btn_de_crt")
        self.horizontalLayout_11.addWidget(self.btn_de_crt)
        self.verticalLayout_4.addLayout(self.horizontalLayout_11)
        self.verticalLayout_4.setStretch(0, 10)
        self.verticalLayout_4.setStretch(1, 1)
        self.groupBox_10 = QtWidgets.QGroupBox(self.groupBox_6)
        self.groupBox_10.setGeometry(QtCore.QRect(10, 20, 111, 291))
        self.groupBox_10.setObjectName("groupBox_10")
        self.val_N_pri = QtWidgets.QTextEdit(self.groupBox_10)
        self.val_N_pri.setGeometry(QtCore.QRect(0, 20, 111, 271))
        self.val_N_pri.setObjectName("val_N_pri")
        self.horizontalLayout_9.addWidget(self.groupBox_6)
        self.horizontalLayout_9.setStretch(0, 100)
        self.horizontalLayout_4.addLayout(self.horizontalLayout_9)
        self.verticalLayout.addLayout(self.horizontalLayout_4)
        self.verticalLayout.setStretch(0, 20)
        self.verticalLayout.setStretch(1, 1)
        self.verticalLayout.setStretch(2, 20)
        self.tabWidget.addTab(self.encryption, "")
        MainWindow.setCentralWidget(self.centralwidget)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)
        self.tabWidget.setCurrentIndex(0)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "naiveRSA"))
        self.label.setText(_translate("MainWindow", "Level"))
        self.comboBox.setItemText(0, _translate("MainWindow", "RSA-768"))
        self.comboBox.setItemText(1, _translate("MainWindow", "RSA-1024"))
        self.comboBox.setItemText(2, _translate("MainWindow", "RSA-2048"))
        self.comboBox.setItemText(3, _translate("MainWindow", "RSA-4096"))
        self.btn_gen.setText(_translate("MainWindow", "Generate"))
        self.gen_time.setText(_translate("MainWindow", "0.00s"))
        self.groupBox_2.setTitle(_translate("MainWindow", "Public Key"))
        self.groupBox_3.setTitle(_translate("MainWindow", "Value N"))
        self.groupBox_4.setTitle(_translate("MainWindow", "Value E"))
        self.groupBox.setTitle(_translate("MainWindow", "Message"))
        self.en_time.setText(_translate("MainWindow", "0.00s"))
        self.btn_en.setText(_translate("MainWindow", "Encrypt Message"))
        self.groupBox_6.setTitle(_translate("MainWindow", "Private Key"))
        self.groupBox_7.setTitle(_translate("MainWindow", "Value D"))
        self.groupBox_8.setTitle(_translate("MainWindow", "Value P"))
        self.groupBox_9.setTitle(_translate("MainWindow", "Value Q"))
        self.groupBox_5.setTitle(_translate("MainWindow", "Encrypted Message"))
        self.de_time.setText(_translate("MainWindow", "0.00s"))
        self.btn_de.setText(_translate("MainWindow", "Decrypt"))
        self.btn_de_crt.setText(_translate("MainWindow", "Decrypt CRT"))
        self.groupBox_10.setTitle(_translate("MainWindow", "Value N"))

