def writeFile(filename):
    with open(filename, "w") as f:
        f.writelines(
            [
                "A187806\n",
                "Software Technology\n",
            ]
        )


def readFile(filename):
    with open(filename, "r") as f:
        content = f.read()
        print(content * 3)


def main():
    filename = "python_file.txt"
    writeFile(filename)
    readFile(filename)


if __name__ == "__main__":
    main()
