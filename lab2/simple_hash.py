import hashlib


def text_to_binary(text):
    return "".join(format(byte, "08b") for byte in text.encode("utf-8"))


def compute_hash(binary_str, algorithm_name):
    hash_object = hashlib.new(algorithm_name)

    remainder = len(binary_str) % 8
    if remainder != 0:
        binary_str = "0" * (8 - remainder) + binary_str

    byte_array = bytearray(
        int(binary_str[i : i + 8], 2) for i in range(0, len(binary_str), 8)
    )

    hash_object.update(byte_array)
    return hash_object.hexdigest()


def process_password(password, output_filename="hash_results.txt"):
    binary_representation = text_to_binary(password)

    algorithms = ["md5", "sha256", "sha512"]
    results = {}

    print("\n--- Двоично представяне ---")
    print(binary_representation)

    print("\n--- Резултати от хеширането (върху двоичния код) ---")

    for algorithm in algorithms:
        hash_value = compute_hash(binary_representation, algorithm)
        results[algorithm] = hash_value

        print(f"\nАлгоритъм: {algorithm.upper()}")
        print(f"Дължина: {len(hash_value) * 4} бита")
        print(f"Хеш: {hash_value}")

    with open(output_filename, "w", encoding="utf-8") as file:
        file.write("РЕЗУЛТАТИ ОТ ХЕШИРАНЕТО\n")
        file.write("=======================\n")
        file.write(f"Парола: {password}\n")
        file.write(f"Двоичен код: {binary_representation}\n\n")

        for algorithm, hash_value in results.items():
            file.write(f"Алгоритъм: {algorithm.upper()}\n")
            file.write(f"Дължина: {len(hash_value) * 4} бита\n")
            file.write(f"Хеш: {hash_value}\n\n")

    print(f"\nРезултатите са записани във файл: {output_filename}")

    return results


def main():
    print("1. Въвеждане на парола от конзолата")
    print("2. Прочитане на парола от текстов файл")

    choice = input("Изберете опция (1 или 2): ").strip()

    if choice == "1":
        password = input("Въведете парола: ")
    elif choice == "2":
        filename = input("Въведете име на текстовия файл: ").strip()

        try:
            with open(filename, "r", encoding="utf-8") as file:
                password = file.read().rstrip("\r\n")
        except OSError as error:
            print(f"Грешка при четене на файла: {error}")
            return

    else:
        print("Невалиден избор!")
        return

    process_password(password)


if __name__ == "__main__":
    main()