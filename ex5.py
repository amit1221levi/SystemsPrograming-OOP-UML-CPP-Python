import string
import os
import json


class VigenereCipher:
    LOWERCASE_ALPHABET = string.ascii_lowercase
    UPPERCASE_ALPHABET = string.ascii_uppercase
    ALPHABET_SIZE = len(LOWERCASE_ALPHABET)

    def __init__(self, keys: list):
        self.keys = keys

    @staticmethod
    def encrypt_letter(self, letter: str, key: int) -> str:
        assert(letter.isalpha())
        letter_index = string.ascii_letters.index(letter)
        moved_letter_index = (letter_index + key) % self.ALPHABET_SIZE
        if letter.isupper():
            return self.UPPERCASE_ALPHABET[moved_letter_index]
        return self.LOWERCASE_ALPHABET[moved_letter_index]

    def encrypt(self, plaintext: str) -> str:
        encrypted = []
        num_of_keys = len(self.keys)
        key_index = 0
        for letter in plaintext:
            if letter.isalpha():
                encrypted.append(self.encrypt_letter(self, letter, self.keys[key_index]))
                key_index = (key_index + 1) % num_of_keys
            else:
                encrypted.append(letter)
        encrypted_text = "".join(encrypted)
        return encrypted_text

    def decrypt(self, ciphertext: str) -> str:
        inverse_vigenere = VigenereCipher([-key for key in self.keys])
        return inverse_vigenere.encrypt(ciphertext)


class CaesarCipher(VigenereCipher):

    def __init__(self, key: int):
        self.keys = [key]  # can't use super


def getVigenereFromStr(keyString: str) -> VigenereCipher:
    vigenere_keys = []
    for letter in keyString:
        if letter.isalpha():
            vigenere_keys.append(string.ascii_letters.index(letter))
    result = VigenereCipher(vigenere_keys)
    return result


def process_files(dir_path: str, cipher: VigenereCipher, mode: str) -> None:
    file_type_to_process = ".txt" if mode == "encrypt" else ".enc"
    for file in os.listdir(dir_path):
        file_path = os.path.join(dir_path, file)
        file_name = os.path.splitext(file)[0]
        file_type = os.path.splitext(file_path)[1]
        if not file_type == file_type_to_process:
            continue
        with open(file_path, 'r') as file_to_process:
            str_to_process = file_to_process.read()
        processed_file_path = os.path.join(dir_path, file_name)
        if mode == "encrypt":
            with open(processed_file_path + ".enc", 'w') as encrypted_file:
                encrypted_file.write(cipher.encrypt(str_to_process))
        else:
            with open(processed_file_path + ".txt", 'w') as decrypted_file:
                decrypted_file.write(cipher.decrypt(str_to_process))


def processDirectory(dir_path: str) -> None:
    config_path = os.path.join(dir_path, "config.json")
    with open(config_path, 'r') as config:
        loaded_config = json.load(config)
    cipher_type = loaded_config['type']
    cipher_mode = loaded_config['mode']
    cipher_key = loaded_config['key']
    if cipher_type == "Caesar":
        cipher = CaesarCipher(cipher_key)
    elif isinstance(cipher_key, str):
        cipher = getVigenereFromStr(cipher_key)
    else:
        cipher = VigenereCipher(cipher_key)
    process_files(dir_path, cipher, cipher_mode)

