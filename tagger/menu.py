import json
import os

def build_json():
    # Step 1: Create an empty JSON file in the current working directory
    json_file_path = "tagger\\data.json"
    with open(json_file_path, "w") as json_file:
        json.dump({}, json_file)

    # Step 2: Read path from input and get all file names in that path
    input_path = input("Enter the path to read files from: ")
    file_names = os.listdir(input_path)

    if not file_names or file_names == []:
        print("No files found in the given path.")
        return

    # Step 3: Write each file name to the JSON file
    with open(json_file_path, "r+") as json_file:
        data = json.load(json_file)
        num = 0
        for file_name in file_names:
            data[file_name] = ""
            print(f"Added {file_name} to the JSON file.")
            num += 1
        json_file.seek(0)
        json.dump(data, json_file, indent=4)
        print(f"{num} items has been created in the JSON file.")


if __name__ == "__main__":
    while True:
        command = input("Enter a command: ")

        """
        quit
        help

        json
            set working directory
            create json
        read json
        write json

        add tag
        remove tag
        edit tag
        show all tags
        """

        if command == "quit":
            break
        elif command == "help":
            pass
        elif command == "build json":
            build_json()
