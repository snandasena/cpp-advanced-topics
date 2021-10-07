import json

def read(data):
    if data['children'] is not None:
        for r in data['children']:
            read(r)

            text: str = r['heading']['text']
            tests = text.split(" ")

            if "figure" == tests[0].lower():
                print(r['heading']['page'], text)

            if "table" == tests[0].lower():
                print(r['heading']['page'], text)


with open("/tmp/ProgrammingComputerVision_CCdraft.json") as f:
    data = json.load(f)
    elements = data['elements']
    for v in elements:
        read(v)
