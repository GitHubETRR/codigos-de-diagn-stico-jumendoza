personas = {
    "Juan": {"edad": 18, "calle": "matheu"},
    "Matip": {"edad": 17, "calle": "urquiza"},
    "Bene": {"edad": 18, "calle": "andres del pino"},
    "Enzo": {"edad": 18, "calle": "arduino"},
    "Kapu": {"edad": 17, "calle": "luis del greco"},
    "Valen": {"edad": 17, "calle": "pasaje carhué"},
    "Gena": {"edad": 18, "calle": "el haras"},
    "Lauti": {"edad": 17, "calle": "castelli"},
    "Tizi": {"edad": 17, "calle": "vigalondo"},
    "Jojo": {"edad": 18, "calle": "balraro"},
    "Galvan": {"edad": 18, "calle": "comelli"},
    "Tutuca": {"edad": 18, "calle": "los paraisos"},
    "Flamant": {"edad": 17, "calle": "petiti"}
}

print ("A quien esta buscando?")
name = input("Nombre:").capitalize()
if name in personas:
    print (name, "está en la crypto, tiene", personas[name]["edad"], "años y vamos a ir el sabado a su casa en", personas[name]["calle"].title())
else:
    print ("este vago no esta en la crypto, que lastima")
