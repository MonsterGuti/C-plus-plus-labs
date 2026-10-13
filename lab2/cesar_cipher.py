def caesar_cipher_cyrillic(text, shift=2):
    alphabet = " АБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЬЮЯ"
    m = 31

    result = []

    for char in text.upper():
        if char in alphabet:
            x = alphabet.index(char)
            encrypted_index = (x + shift) % m
            result.append(alphabet[encrypted_index])
        else:
            result.append(char)

    return "".join(result)


message = "НИЕ СМЕ СТУДЕНТИ ОТ ТУ СОФИЯ"

encrypted = caesar_cipher_cyrillic(message, shift=2)

print("Оригинално съобщение:", message)
print("Шифровано съобщение:", encrypted)
