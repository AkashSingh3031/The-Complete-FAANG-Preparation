
# Contributed by Paraj Shah
# https://github.com/parajshah

def designerPdfViewer(h, word):
    height = 0
    for c in word:
        height = max(height, h[ord(c) - ord("a")])
    return height * len(word)