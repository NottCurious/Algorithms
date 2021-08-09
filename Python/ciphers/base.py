import base64

def encode_b16(inp) -> bytes:
    encoded = inp.encode('utf-8')
    b16encoded = base64.b16encode(encoded)
    return b16encoded

def encode_b32(inp) -> bytes:
    encoded = inp.encode('utf-8')
    b32encoded = base64.b32encode(encoded)
    return b32encoded

def encode_b64(inp) -> bytes:
    encoded = inp.encode('utf-8')
    b64encoded = base64.b64encode(encoded)
    return b64encoded

def encode_b85(inp) -> bytes:
    encoded = inp.encode('utf-8')
    a85encoded = base64.a85encode(encoded)
    return a85encoded

if __name__ == '__main__':
    n = input("Input: ")

    print(encode_b16(n))
    print(encode_b32(n))
    print(encode_b64(n))
    print(encode_b85(n))