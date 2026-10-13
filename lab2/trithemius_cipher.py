
def trithemius_cipher(message, key):
    alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    result = []

    message = message.upper()
    key = key.upper()

    for i, char in enumerate(message):
        if char in alphabet:
            text_code = alphabet.index(char)

            key_char = key[i % len(key)]
            key_code = alphabet.index(key_char)

            encrypted_code = (i + text_code + key_code) % 26

            result.append(alphabet[encrypted_code])
        else:
            result.append(char)

    return "".join(result)


message = "SETSRELATIONSANDFUNCTIONS"
key = "PROGRAM"

encrypted = trithemius_cipher(message, key)

print("Изходно съобщение:", message)
print("Ключ:", key)
print("Шифрограма:", encrypted)
