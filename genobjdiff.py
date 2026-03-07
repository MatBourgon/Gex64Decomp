import yaml
import json

try:
    from yaml import CLoader as Loader, CDumper as Dumper
except:
    from yaml import Loader, Dumper

def CreateSegmentDefinition(name, path, hasBasePath, category):
    return [{
        "name": name,
        "target_path": f"build/asm{path}{name}.o",
        "base_path": f"build/src{path}{name}.o" if hasBasePath else None,
        "metadata": {
            "progress_categories": [
                category
            ]
        }
    }]

def ParseSubsegmentLabel(label, offset):
    if label is None:
        return ("/", hex(offset)[2:].upper())
    elif label.rfind("/") == -1:
        return ("/", label)
    else:
        return ("/" + label[:label.rfind("/") + 1], label[label.rfind("/") + 1:])

def ParseMainSegment(segment):
    subsegments = []
    for subsegment in segment["subsegments"]:
        if isinstance(subsegment, list):
            offset = subsegment[0] if len(subsegment) > 0 else None
            subtype = subsegment[1] if len(subsegment) > 1 else None
            label = subsegment[2] if len(subsegment) > 2 else None
            (path, name) = ParseSubsegmentLabel(label, offset)
            match subtype:
                case "c":
                    subsegments.extend(CreateSegmentDefinition(name, path, True, "game" if offset <= 0x56340 else "sdk"))
                case "asm" | "hasm":
                    subsegments.extend(CreateSegmentDefinition(name, path, False, "game" if offset <= 0x56340 else "sdk"))
    return subsegments

def ParseLevelSegment(segment):
    return CreateSegmentDefinition(segment["name"], "/", True, "level")

def ParseSegment(segment):
    try:
        match segment["type"]:
            case "code":
                match segment["name"]:
                    case "entry":
                        return None
                    case "main":
                        return ParseMainSegment(segment)
                    case "zlib":
                        return CreateSegmentDefinition("zlib", "/", True, "sdk")
                    case _:
                        return ParseLevelSegment(segment)
            case _:
                return None
    except Exception as e:
        return None

def CreateObjJSON(segments):
    return {
        "$schema": "https://raw.githubusercontent.com/encounter/objdiff/main/config.schema.json",
        "units": segments,
        "progress_categories": [
            {
                "id": "game",
                "name": "Game"
            },
            {
                "id": "sdk",
                "name": "SDK"
            },
            {
                "id": "level",
                "name": "Level"
            }
        ]
    }

try:
    with open("gexenterthegecko.yaml", "r") as f:
        y = yaml.load(f.read(), Loader=Loader)
        segments = []
        for segment in y["segments"]:
            segmentData = ParseSegment(segment)
            if segmentData is not None:
                segments.extend(segmentData)
        if len(segments) == 0:
            print("Error: No segments detected")
            exit(1)

        objdiffjson = CreateObjJSON(segments)
        
        with open("objdiff.json", "w") as fo:
            json.dump(objdiffjson, fo)
except:
    exit(1)