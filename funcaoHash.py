import hashlib


arquivo = input("Digite o caminho do arquivo: ")
algoritmo = input("Digite o modelo para gerar o hash (1 = sha256 ou  2 = sha1): ")

def gerarHashDoArquivo(arquivo, algoritmo):

    if algoritmo == '1':
        funcaoHash = hashlib.sha256()
    elif algoritmo == '2':
        funcaoHash = hashlib.sha1()
    else:
        print("Algoritmo não suportado. Escolha entre 'sha256' e 'sha1'.")
        return None

    try:
        with open(arquivo, "rb") as f:
            while chunk := f.read(8192):
                funcaoHash.update(chunk)
        return funcaoHash.hexdigest() 
    except FileNotFoundError:
        print("Arquivo não encontrado.")
        return None
    except Exception as e:
        print(f"Ocorreu um erro: {e}")
        return None

hashArquivo = gerarHashDoArquivo(arquivo, algoritmo)
if hashArquivo:
    print("Hash do arquivo:", hashArquivo)



