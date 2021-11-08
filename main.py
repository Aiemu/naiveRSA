# This is a sample Python script.

# Press ⌃R to execute it or replace it with your code.
# Press Double ⇧ to search everywhere for classes, files, tool windows, actions, and settings.
import random
import threading
import time
import sys
from ui import Ui_MainWindow
from PyQt5.QtWidgets import QApplication, QMainWindow, QMessageBox

sys.setrecursionlimit(100000)


def generate_random_int_less(num):
    return random.randint(2, num)


def generate_random_int(length):
    ret = random.getrandbits(length)
    if ret % 2 == 0:
        return ret - 1
    else:
        return ret


def gcd(a, b):
    while b != 0:
        tmp = a % b
        a = b
        b = tmp
    return a


def fast_pow(num, k, mod):
    ret = 1
    while k > 0:
        if k % 2 == 1:
            ret = ret * num % mod
        num = num * num % mod
        k = k // 2
    return ret


def inverse(e, phi_n):
    arr = [0, 1, ]
    ret = extended_euclid(e, phi_n, arr)
    if ret == 1:
        return (arr[0] % phi_n + phi_n) % phi_n
    else:
        return -1


def extended_euclid(a, phi_n, arr):
    if phi_n == 0:
        arr[0] = 1
        arr[1] = 0
        return a
    ret = extended_euclid(phi_n, a % phi_n, arr)
    tmp = arr[0]
    arr[0] = arr[1]
    arr[1] = tmp - a // phi_n * arr[1]
    return ret


def get_e(phi_n):
    while True:
        _e = random.randint(2, phi_n)
        if gcd(_e, phi_n) == 1:
            return _e


def is_composite(a, m, k, num):
    if fast_pow(int(a), int(m), int(num)) == 1:
        return False
    for j in range(k):
        if fast_pow(int(a), int(m * (2 ** j)), int(num)) == num - 1:
            return False
    return True


def is_prime(num, certainty):
    prime_list = [3, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101,
                  103,
                  107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199,
                  211,
                  223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317,
                  331,
                  337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443,
                  449,
                  457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577,
                  587,
                  593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701,
                  709,
                  719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839,
                  853,
                  857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983,
                  991,
                  997, 1009, 1013, 1019, 1021, 1031, 1033, 1039, 1049, 1051, 1061, 1063, 1069, 1087, 1091, 1093,
                  1097,
                  1103, 1109, 1117, 1123, 1129, 1151, 1153, 1163, 1171, 1181, 1187, 1193, 1201, 1213, 1217, 1223,
                  1229,
                  1231, 1237, 1249, 1259, 1277, 1279, 1283, 1289, 1291, 1297, 1301, 1303, 1307, 1319, 1321, 1327,
                  1361,
                  1367, 1373, 1381, 1399, 1409, 1423, 1427, 1429, 1433, 1439, 1447, 1451, 1453, 1459, 1471, 1481,
                  1483,
                  1487, 1489, 1493, 1499, 1511, 1523, 1531, 1543, 1549, 1553, 1559, 1567, 1571, 1579, 1583, 1597,
                  1601,
                  1607, 1609, 1613, 1619, 1621, 1627, 1637, 1657, 1663, 1667, 1669, 1693, 1697, 1699, 1709, 1721,
                  1723,
                  1733, 1741, 1747, 1753, 1759, 1777, 1783, 1787, 1789, 1801, 1811, 1823, 1831, 1847, 1861, 1867,
                  1871,
                  1873, 1877, 1879, 1889, 1901, 1907, 1913, 1931, 1933, 1949, 1951, 1973, 1979, 1987, 1993, 1997,
                  1999]
    for prime in prime_list:
        if num == prime:
            return True
        if num % prime == 0:
            return False
    m = num - 1
    k = 0
    while m % 2 == 0:  # num - 1 = m * 2 ^ k
        m = m // 2
        k += 1

    for i in range(certainty):
        a = generate_random_int_less(num - 1)
        if is_composite(a, m, k, num):
            return False
    return True


def generate_random_prime(length, certainty):
    ret = generate_random_int(length)

    while not is_prime(ret, certainty):
        # print(ret)
        ret += 2
    return ret


class MyThread(threading.Thread):
    def __init__(self, target, args, name):
        super(MyThread, self).__init__()
        self.target = target
        self.args = args
        self.prime = 2
        self.name = name

    def run(self):
        start = time.time()
        self.prime = self.target(*self.args)
        print(self.name, time.time() - start)

    def get_prime(self):
        try:
            return self.prime
        except Exception:
            return None


class MyMainForm(QMainWindow, Ui_MainWindow):
    def __init__(self, parent=None):
        super(MyMainForm, self).__init__(parent)
        self.setupUi(self)
        self.btn_en.clicked.connect(self.encrypt)
        self.btn_de.clicked.connect(self.decrypt)
        self.btn_de_crt.clicked.connect(self.crt_decrypt)
        self.btn_gen.clicked.connect(self.generate_key)
        self.n = 0
        self.e = 0
        self.d = 0
        self.p = 0
        self.q = 0
        self.ciphertext = ''
        self.message = ''

    def generate_key(self):
        type = self.comboBox.currentText()
        len = 0
        if type == 'RSA-768':
            len = 768
        elif type == 'RSA-1024':
            len = 1024
        elif type == 'RSA-2048':
            len = 2048
        elif type == 'RSA-4096':
            len = 4096

        start = time.time()

        # multi threads

        # random.seed(10)
        # try:
        #     thread_p = MyThread(target=generate_random_prime, args=(len // 2, 5), name='p')
        #     thread_q = MyThread(target=generate_random_prime, args=(len // 2, 5), name='q')
        # except:
        #     print('Error: unable to start thread')
        #     return
        # thread_q.start()
        # thread_p.start()
        # thread_q.join()
        # thread_p.join()
        # gen_p = thread_p.get_prime()
        # gen_q = thread_q.get_prime()

        # start = time.time()
        gen_p = generate_random_prime(len // 2, 5)
        # print('p:', time.time() - start)
        # start = time.time()
        gen_q = generate_random_prime(len // 2, 5)
        # print('q:', time.time() - start)
        gen_n = gen_p * gen_q
        phi_n = (gen_p - 1) * (gen_q - 1)
        gen_e = get_e(phi_n)
        gen_d = inverse(gen_e, phi_n)
        self.gen_time.setText(str(round(time.time() - start, 4)) + 's')
        self.n = gen_n
        self.e = gen_e
        self.d = gen_d
        self.p = gen_p
        self.q = gen_q
        # print(hex(self.n))
        # print(hex(self.d))
        # print(hex(self.e))
        # print(hex(self.p))
        # print(hex(self.q))
        self.val_N_pub.setText(str(hex(gen_n))[2:])
        self.val_N_pri.setText(str(hex(gen_n))[2:])
        self.val_E.setText(str(hex(gen_e))[2:])
        self.val_D.setText(str(hex(gen_d))[2:])
        self.val_P.setText(str(hex(gen_p))[2:])
        self.val_Q.setText(str(hex(gen_q))[2:])
        return gen_n, gen_e, gen_d, gen_p, gen_q

    def encrypt(self):
        try:
            # print(self.val_N.toPlainText())
            self.n = int(self.val_N_pub.toPlainText(), base=16)
            self.e = int(self.val_E.toPlainText(), base=16)
            self.message = self.message_input.toPlainText()
        except:
            QMessageBox.warning(self, '提示', '请检查公钥和明文', QMessageBox.No | QMessageBox.Yes, QMessageBox.Yes)
            return

        if self.message == '':
            QMessageBox.warning(self, '提示', '请填写明文', QMessageBox.No | QMessageBox.Yes, QMessageBox.Yes)
            return

        start = time.time()
        self.ciphertext = ''
        for i in range(-(-len(self.message) // 20)):
            m_slice = int.from_bytes(self.message[20 * i: 20 * (i + 1)].encode("utf-8"), byteorder="big")
            # print('m_slice:', m_slice)
            c_slice = fast_pow(m_slice, self.e, self.n)
            # print('c_slice:', hex(c_slice))
            self.ciphertext += '<ciphertext>' + str(hex(c_slice)[2:]) + '</ciphertext>\n'
        self.ciphertext_input.setText(self.ciphertext)
        self.en_time.setText(str(round(time.time() - start, 4)) + 's')
        # return self.fast_pow(self.message, self.e, self.n)

    def decrypt(self):
        try:
            # print(self.val_N.toPlainText())
            self.n = int(self.val_N_pri.toPlainText(), base=16)
            self.d = int(self.val_D.toPlainText(), base=16)
            self.ciphertext = self.ciphertext_input.toPlainText()
        except:
            QMessageBox.warning(self, '提示', '请检查私钥和明文', QMessageBox.No | QMessageBox.Yes, QMessageBox.Yes)
            return

        if self.ciphertext == '':
            QMessageBox.warning(self, '提示', '请填写密文', QMessageBox.No | QMessageBox.Yes, QMessageBox.Yes)
            return

        start = time.time()
        c_list = self.ciphertext_input.toPlainText().split('\n')
        # print(c_list)
        m = ''
        # print(hex(self.n))
        # print(hex(self.d))
        for i in range(len(c_list) - 1):
            m_slice = fast_pow(int(c_list[i][12:-13], base=16), self.d, self.n)
            # print('m_slice:', m_slice)
            m += m_slice.to_bytes(((m_slice.bit_length() + 7) // 8), byteorder="big").decode("utf-8")

        self.ciphertext_input.setText(m)
        self.de_time.setText(str(round(time.time() - start, 4)) + 's')

        # return self.fast_pow(self.ciphertext, self.d, self.n)

    def crt_decrypt(self):
        try:
            # print(self.val_N.toPlainText())
            self.n = int(self.val_N_pri.toPlainText(), base=16)
            self.d = int(self.val_D.toPlainText(), base=16)
            self.p = int(self.val_P.toPlainText(), base=16)
            self.q = int(self.val_Q.toPlainText(), base=16)
            self.ciphertext = self.ciphertext_input.toPlainText()
        except:
            QMessageBox.warning(self, '提示', '请检查私钥和明文', QMessageBox.No | QMessageBox.Yes, QMessageBox.Yes)
            return

        if self.ciphertext == '':
            QMessageBox.warning(self, '提示', '请填写密文', QMessageBox.No | QMessageBox.Yes, QMessageBox.Yes)
            return

        start = time.time()
        c_list = self.ciphertext_input.toPlainText().split('\n')
        # print(c_list)
        m = ''
        # print(self.n)
        # print(self.d)
        for i in range(len(c_list) - 1):
            m_slice = (fast_pow(int(c_list[i][12:-13], base=16) % self.q, self.d % (self.q - 1), self.q) *
                       self.p * inverse(self.p, self.q) +
                       fast_pow(int(c_list[i][12:-13], base=16) % self.p, self.d % (self.p - 1), self.p) *
                       self.q * inverse(self.q, self.p)) % self.n
            # print('m_slice: ', m_slice)
            m += m_slice.to_bytes(((m_slice.bit_length() + 7) // 8), byteorder="big").decode("utf-8")

        self.ciphertext_input.setText(m)
        self.de_time.setText(str(round(time.time() - start, 4)) + 's')
        # return (fast_pow(self.ciphertext % self.q, self.d % (self.q - 1), self.q) *
        #         self.p * self.inverse(self.p, self.q) +
        #         fast_pow(self.ciphertext % self.p, self.d % (self.p - 1), self.p) *
        #         self.q * self.inverse(self.q, self.p)) % self.n


if __name__ == '__main__':
    app = QApplication(sys.argv)
    myWin = MyMainForm()
    myWin.show()
    sys.exit(app.exec_())

    # print('Generate Key...')
    # start = time.time()
    # n, e, d, p, q = generate_key(1024, 5)
    # print(time.time() - start)
    #
    # m = 'test'
    # c = ''
    # m_list = []
    # c_list = []
    #
    # print('Encryption...')
    # start = time.time()
    # for i in range(-(-len(m) // 20)):
    #     m_slice = int.from_bytes(m[20 * i: 20 * (i + 1)].encode("utf-8"), byteorder="big")
    #     c_slice = encrypt(m_slice, e, n)
    #     # print(c_slice)
    #     c_list.append(c_slice)
    #     c += '<ciphertext>' + str(hex(int(c_slice))) + '</ciphertext>\n'
    #
    # print(time.time() - start)
    #
    # print('Decryption:')
    # start = time.time()
    # c_list = c.split('\n')
    # m = ''
    # for i in range(len(c_list) - 1):
    #     m_slice = decrypt(int(c_list[i][12:-13], base=0), d, n)
    #     m += m_slice.to_bytes(((m_slice.bit_length() + 7) // 8), byteorder="big").decode("utf-8")
    #
    # print(time.time() - start)
    # print(m)
    #
    # print('Decryption with CRT:')
    # start = time.time()
    # c_list = c.split('\n')
    # m = ''
    # for i in range(len(c_list) - 1):
    #     m_slice = crt_decrypt(int(c_list[i][12:-13], base=0), d, n, p, q)
    #     m += m_slice.to_bytes(((m_slice.bit_length() + 7) // 8), byteorder="big").decode("utf-8")
    #
    # print(time.time() - start)
    # print(m)
