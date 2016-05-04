//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "RecordsFormUnit.h"
#include "HomeFormUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TRecordsForm *RecordsForm;
//---------------------------------------------------------------------------
__fastcall TRecordsForm::TRecordsForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TRecordsForm::Image2Click(TObject *Sender)
{
  HomeForm->Show();
  RecordsForm->Hide();
}
//---------------------------------------------------------------------------
void __fastcall TRecordsForm::Image3Click(TObject *Sender)
{
  int idSeleccionado = ComboBox1->ItemIndex;

  if (idSeleccionado >= 0) {
    GanadasLabel->Caption = HomeForm->jugadores[idSeleccionado].ganadas;
    PerdidasLabel->Caption = HomeForm->jugadores[idSeleccionado].perdidas;
    EmpatadasLabel->Caption = HomeForm->jugadores[idSeleccionado].empatadas;
  }

          
}
//---------------------------------------------------------------------------
void __fastcall TRecordsForm::FormActivate(TObject *Sender)
{
  for(int i = 0; i < HomeForm->nJugadores; i++) {
    ComboBox1->AddItem(HomeForm->jugadores[i].nick, ComboBox1);
  }        
}
//---------------------------------------------------------------------------

void __fastcall TRecordsForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  HomeForm->Close();        
}
//---------------------------------------------------------------------------

