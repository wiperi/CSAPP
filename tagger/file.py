class File:

    # member var
    file_name = ""
    tags = {}

    def __init__(self, file_name: str, tags: dict) -> None:
        self.file_name = file_name
        self.tags = tags