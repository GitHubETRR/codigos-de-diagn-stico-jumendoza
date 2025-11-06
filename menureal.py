personas = {}

def agregar_persona():
    print ("\nIngrese los datos de su persona")
    nombre = input("Ingrese su nombre: ").lower()
    edad = int(input("Ingrse su edad: "))
    calle = input("Ingrese la calle donde vive: ")
    personas[nombre] = {"edad": edad, "calle": calle}
    print ("Persona agregada con exito")

def ver_personas():
    if not personas:
        print("\nNo hay personas todavía")
    else:
        print("\n Lista de personas:")
        for nombre, datos in personas.items():
            print(". ", nombre.capitalize(), ", tiene", datos["edad"], "años y vive en la calle", datos["calle"].title())

def menu():
    opcion = ""
    while opcion != "3":
        print("\n--------MENU PRINCIPAL--------")
        print("¿Que quiere hacer? Seleccione un numero:")
        print("1. Agregar persona")
        print("2. Ver personas")
        print("3. Salir")
        opcion = input("Opcion:")
        if opcion == "1":
            agregar_persona()
        elif opcion == "2":
            ver_personas()
        elif opcion == "3":
            print("Cerrando el sistema...")
        else:
            print("Opcion no valida, eliga otra")
menu()
