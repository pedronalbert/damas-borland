//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SelecJugadoresUnit.h"
#include "JuegoFormUnit.h"
#include "HomeFormUnit.h"
#include "RegistrarUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TSelecJugadoresForm *SelecJugadoresForm;
//---------------------------------------------------------------------------
__fastcall TSelecJugadoresForm::TSelecJugadoresForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TSelecJugadoresForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  HomeForm->Close();
}
//---------------------------------------------------------------------------



void __fastcall TSelecJugadoresForm::RegistrarButtonClick(TObject *Sender)
{
  RegistrarForm->Show();
  SelecJugadoresForm->Hide();
}
//---------------------------------------------------------------------------

void __fastcall TSelecJugadoresForm::FormShow(TObject *Sender)
{
  for(int i = 0; i < HomeForm->nJugadores; i++) {
    ComboBox1->AddItem(HomeForm->jugadores[i].nick, ComboBox1);
    ComboBox2->AddItem(HomeForm->jugadores[i].nick, ComboBox1);
  }
}
//---------------------------------------------------------------------------

void __fastcall TSelecJugadoresForm::Button1Click(TObject *Sender)
{
  int idJugador1 = ComboBox1->ItemIndex;       
  int idJugador2 = ComboBox2->ItemIndex;
  int idAvatarJugador1 = ComboBox4->ItemIndex;
  int idAvatarJugador2 = ComboBox5->ItemIndex;

  if (idJugador1 < 0 || idJugador2 < 0) {
    ShowMessage("Debe seleccionar dos jugadores");
    return;
  }

  if (idJugador1 == idJugador2) {
    ShowMessage("Los jugadores deben que ser distintos");
    return;
  }

  if(idAvatarJugador1 < 0 || idAvatarJugador2 < 0) {
    ShowMessage("Debe seleccionar los avatares");
    return;
  }

  if(idAvatarJugador2 == idAvatarJugador1) {
    ShowMessage("Los avatares deben ser distintos");
    return;
  }

  JuegoForm->setJugadoresIds(idJugador1, idJugador2);
  JuegoForm->setAvataresIds(idAvatarJugador1, idAvatarJugador2);
  JuegoForm->Show();
  SelecJugadoresForm->Hide();

}
//---------------------------------------------------------------------------

void __fastcall TSelecJugadoresForm::Image2Click(TObject *Sender)
{
  HomeForm->Show();
  SelecJugadoresForm->Hide();        
}
//---------------------------------------------------------------------------


void __fastcall TSelecJugadoresForm::ComboBox4Change(TObject *Sender)
{
  int avatarIndex = ComboBox4->ItemIndex;

  AvatarList->Draw(Avatar1->Canvas,0, 0, avatarIndex, true);
}
//---------------------------------------------------------------------------

void __fastcall TSelecJugadoresForm::ComboBox5Change(TObject *Sender)
{
  int avatarIndex = ComboBox5->ItemIndex;

  AvatarList->Draw(Avatar2->Canvas,0, 0, avatarIndex, true);
}
//---------------------------------------------------------------------------

