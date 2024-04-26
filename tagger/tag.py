class Tag:
    
    name = None
    father_tag = None
    sub_tags = []
    files = []

    def __init__(self, name: str, father_tag, sub_tags: list, files: list) -> None:
        self.name = name
        self.father_tag = father_tag
        self.sub_tags = sub_tags
        self.files = files