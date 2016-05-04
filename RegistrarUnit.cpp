//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "RegistrarUnit.h"
#include "SelecJugadoresUnit.h"
#include "HomeFormUnit.h"
#include <iostream>
#include <fstream>
using namespace std;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TRegistrarForm *RegistrarForm;
//---------------------------------------------------------------------------
__fastcall TRegistrarForm::TRegistrarForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TRegistrarForm::Image2Click(TObject *Sender)
{
  SelecJugadoresForm->Show();
  RegistrarForm->Hide();
}
//---------------------------------------------------------------------------

void __fastcall TRegistrarForm::RegistrarButtonClick(TObject *Sender)
{
  //validamos que no hayan datos vacios
  AnsiString nick = Edit1->Text;       
  AnsiString nombre = Edit2->Text;       
  AnsiString apellido = Edit3->Text;       
  AnsiString correo = Edit4->Text;


  if(nick.IsEmpty() || nombre.IsEmpty() || apellido.IsEmpty()) {
    ShowMessage("Debe llenar todos los datos");
  } else {
    bool nickRepetido = false;
    //verificamos que no sea un nick duplicado
    for (int i = 0; i < HomeForm->nJugadores; i++) {
      if(HomeForm->jugadores[i].nick == nick) {
        nickRepetido = true;
      }
    }

    if(nickRepetido) {
      ShowMessage("Ya existe un jugador con ese nick");
    } else {
      int nJugadores = HomeForm->nJugadores;
      HomeForm->jugadores[nJugadores].nick = nick;
      HomeForm->jugadores[nJugadores].nombre = nombre;
      HomeForm->jugadores[nJugadores].apellido = apellido;
      HomeForm->jugadores[nJugadores].correo = correo;
      HomeForm->jugadores[nJugadores].ganadas = 0;
      HomeForm->jugadores[nJugadores].perdidas = 0;
      HomeForm->jugadores[nJugadores].empatadas = 0;
      HomeForm->nJugadores++;

      //guardamos en un archivo
      
      ofstream archivo;
      archivo.open(AnsiString("archivos/datos/" + nick + ".txt").c_str());
      archivo << "Nick: " << nick.c_str() << endl;
      archivo << "Nombre: " << nombre.c_str() << endl;
      archivo << "Apellido: " << apellido.c_str() << endl;
      archivo << "Correo: " << correo.c_str() << endl;
      archivo.close();

      ShowMessage("Jugador Registrado satisfactoriamente");
      this->limpiarEdits();
    }
  }
}

void TRegistrarForm::limpiarEdits() {
  Edit1->Clear();
  Edit2->Clear();
  Edit3->Clear();
  Edit4->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TRegistrarForm::FormShow(TObject *Sender)
{
  this->limpiarEdits();        
}
//---------------------------------------------------------------------------

void __fastcall TRegistrarForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  HomeForm->Close();        
}
//---------------------------------------------------------------------------

