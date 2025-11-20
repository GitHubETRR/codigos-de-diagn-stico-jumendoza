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

def eliminar_personas():
    eliminar = input("\nA quien desea eliminar:").lower()
    if eliminar in personas:
        del personas[eliminar]
        print("Persona eliminada correctamente")
    else:
        print("No se encontro a esa persona")

def buscar_personas():
    buscar = input("\nA quien desea buscar: ").lower()
    if buscar in personas:
        datos = personas[buscar]
        print(". ", buscar.capitalize(), ",tiene", datos["edad"], "años y vive en la calle", datos["calle"].title())
    else:
        print("Persona no encontrada")

def menu():
    opcion = ""
    while opcion != "5":
        print("\n--------MENU PRINCIPAL--------")
        print("¿Que quiere hacer? Seleccione un numero:")
        print("1. Agregar persona")
        print("2. Ver personas")
        print("3. Eliminar personas")
        print("4. Buscar personas")
        print("5. Salir")
        opcion = input("Opcion:")
        if opcion == "1":
            agregar_persona()
        elif opcion == "2":
            ver_personas()
        elif opcion == "3":
            eliminar_personas()
        elif opcion == "4":
            buscar_personas()
        elif opcion == "5":
            print("Cerrando el sistema...")
        else:
            print("Opcion no valida, eliga otra")
menu()
