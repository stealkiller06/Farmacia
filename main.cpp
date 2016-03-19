#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

//creando nuestra estructura
struct Producto{
	int codigo;
	char principioActivo[20];
	char accionFarmacologica[50];
	char marca[20];
	char vencimiento[10];
	char presentacion[15];
	char laboratorio[20];
	int cantidad;
	float precio;
	Producto *ptrsig;
};

//declarando nuestros punteros auxiliares para manipular nuestra estructura
Producto *nuevo, *aux, *inicio, *anterior;

//----------------------------------------------------------------Funcion para facturar---------------------------------------------
void facturacion()
{
	system("cls");
	cout << "Esta opcion esta en mantenimiento" << endl;
	system("cls");
}
//---------------------------------------------------------Funcion registrar producto-------------------------------------------
void registrarProducto()
{

	//----------verificando si es el primer nodo que crearemos-----------
	if (inicio == NULL)
	{
		cout << "Este es el primer nodo que vas a crear" << endl;
		nuevo = new (Producto);

		cout << "*---Registrando Producto---*" << endl;
		cout << "Codigo: " ;
		cin >> nuevo->codigo;
		cout << "Marca: ";
		cin >> nuevo->marca;
		cout << "Principio Activo: ";
		cin >> nuevo->principioActivo;
		cout << "Accion Farmacologica: ";
		cin >> nuevo->accionFarmacologica;
		cout << "Fecha de vencimiento: ";
		cin >> nuevo->vencimiento;
		cout << "Presentacion: ";
		cin >> nuevo->presentacion;
		cout << "Laboratorio: ";
		cin >> nuevo->laboratorio;
		cout << "Cantidad de productos: ";
		cin >> nuevo->cantidad;
		cout << "Precio: ";
		cin >> nuevo->precio;

		//-----Manipulando los punteros----------
		inicio = nuevo;
		aux = nuevo;
		nuevo->ptrsig = NULL;

		//Mensaje de exito
		cout << "*---Agregado con exito---*" << endl;
	}
	else{
		//---------Agregando Nuevo Producto-------------
		aux = inicio; //c
		
		//------Posicionando al puntero aux en el ultimo producto creado----
		while(aux->ptrsig != NULL)
		{
			aux = aux->ptrsig;//C
		}
		nuevo = new(Producto);
		cout << "*---Registrando Producto---*" << endl;
		cout << "Codigo: " ;
		cin >> nuevo->codigo;
		cout << "Marca: ";
		cin >> nuevo->marca;
		cout << "Principio Activo: ";
		cin >> nuevo->principioActivo;
		cout << "Accion Farmacologica: ";
		cin >> nuevo->accionFarmacologica;
		cout << "Fecha de vencimiento: ";
		cin >> nuevo->vencimiento;
		cout << "Presentacion: ";
		cin >> nuevo->presentacion;
		cout << "Laboratorio: ";
		cin >> nuevo->laboratorio;
		cout << "Cantidad de productos: ";
		cin >> nuevo->cantidad;
		cout << "lugar 1a" << endl;
		cout << "Precio: ";
		cin >> nuevo->precio;

		//--------------------manipulaicon de punteros--------------
		aux->ptrsig = nuevo;
		aux = nuevo;
		nuevo->ptrsig = NULL;

	}
}
//------------------------------------------ ver productos----------------------------------------------
void verProductos()
{

	if(inicio == NULL)
	{
		cout << "No ha ingresado ningun producto!" << endl;
	}
	else{
	cout <<setw(10)<< "Codigo" << setw(20) <<"Marca" <<setw(25) <<"Principio Activo"  <<setw(15)
	 <<"Vencimiento"<<setw(15)<<"Presentacion"	<< setw(20) << "Laboratorio" << setw(10) << "Cantidad" << setw(10) << "Precio" << endl;
	aux = inicio;
	while (aux != NULL)
	{
		cout <<setw(10)<< aux->codigo << setw(20) << aux->marca <<setw(25) <<aux->principioActivo <<
		setw(20) <<setw(15) <<aux->vencimiento<<setw(15)<<aux->presentacion
		<< setw(20) << aux->laboratorio << setw(10) << aux->cantidad << setw(10) << aux->precio << endl;
		aux = aux->ptrsig;
		
	}
}
	system("Pause");
}


//-----------------------------------------------Eliminar Producto---------------------------------------------------
void eliminar()
{
	int codigo;
	
	cout << "Ingrese el codigo del producto: ";
	cin >> codigo;
	if(inicio == NULL)
	{
		cout  << "No ha ingresado ningun medicamento." << endl;
	}
	else
	{
		aux = inicio;
		anterior = NULL;
		
		//Buscando el producto
		while(aux != NULL && aux->codigo != codigo)
		{
			anterior = aux;
			aux = aux->ptrsig;
		}
		if(aux == NULL)
		{
			cout << "Producto no encontrado..." << endl;
		}
		else
		{
			//el producto fue encontrado!
			
			//el producto se encuentra en el inicio
			if(anterior == NULL)
			{
				inicio = inicio->ptrsig;
			}
			//el producto se encuentra en otro lugar diferente de inicio
			else
			{
				anterior->ptrsig = aux->ptrsig;		
			}
			delete(aux);
			cout << "Producto Eliminado!"<< endl;
		}
		
	}
	system("pause");
}
//--------------------------------------------------Menu Inventario-----------------------------------------------------------------
void inventario()
{
	system("cls");
	int op;
	do{
	
	cout << "************************************************************" << endl;
	cout << "*                      Inventario                          *" << endl;
	cout << "************************************************************" << endl;
	cout << "1.Agregar nuevo producto" << endl;
	cout << "2.Eliminaro Producto" << endl;
	cout << "3.Ver todos los productos" << endl;
	cout << "0.Regresar" << endl;
	cin >> op;
	
	switch(op)
	{
		case 0:
			{
				system("cls");
				break;
			}
		case 1:
			{
				system("cls");
				registrarProducto();
				system("cls");
				break;
			}
		
		case 2:
			{
				system("cls");
				eliminar();
				system("cls");
				break;
			}
		case 3:
			{
				system("cls");
				verProductos();
				system("cls");
				break;
			}
			
			
	}
	}while(op!=0);
}



//-----------Funcion Principal---------------------
int main(){
	//---------Inicializando los punteros--------
	inicio = NULL;
	aux = NULL;
	nuevo = NULL;

	int op;

	do {
		cout << "************************************************************" << endl;
		cout << "*                   Menu Principal                         *" << endl;
		cout << "************************************************************" << endl;
		cout << "*                  1.Facturaracion                         *" << endl;
		cout << "*                  2.Inventario                         	*" << endl;
		cout << "*                  3.Productos en agotamiento              *" << endl;
		cout << "*                  0.Salir                                 *" << endl;
		cout << "************************************************************" << endl;
		cin >> op;

		switch(op)
		{
			case 1:
				{
					/*facturacion(&producto1);*/
					break;
				}
			case 2:
				{
					system("cls");
					inventario();
					break;
				}
			case 5:
				{
					
					verProductos();
					break;
				}
		}



	}while(op!= 0);


}
