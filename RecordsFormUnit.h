//---------------------------------------------------------------------------

#ifndef RecordsFormUnitH
#define RecordsFormUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TRecordsForm : public TForm
{
__published:	// IDE-managed Components
        TImage *Image1;
        TLabel *Label1;
        TImage *Image2;
        TLabel *Label2;
        TComboBox *ComboBox1;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *GanadasLabel;
        TLabel *PerdidasLabel;
        TLabel *EmpatadasLabel;
        TImage *Image3;
        void __fastcall Image2Click(TObject *Sender);
        void __fastcall Image3Click(TObject *Sender);
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
        __fastcall TRecordsForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TRecordsForm *RecordsForm;
//---------------------------------------------------------------------------
#endif
