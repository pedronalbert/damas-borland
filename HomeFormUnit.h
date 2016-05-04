//---------------------------------------------------------------------------

#ifndef HomeFormUnitH
#define HomeFormUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <Menus.hpp>
#include <MPlayer.hpp>
//---------------------------------------------------------------------------
typedef struct {
  AnsiString nick;
  AnsiString nombre;
  AnsiString apellido;
  AnsiString correo;
  int ganadas;
  int perdidas;
  int empatadas;
} Jugador;

class THomeForm : public TForm
{
__published:	// IDE-managed Components
        TImage *NuevoJuegoButton;
        TImage *Image1;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TImage *Image2;
        TImage *Image3;
        TImage *Image4;
        TMainMenu *MainMenu1;
        TMenuItem *Creditos1;
        TMenuItem *NuevoJuego1;
        TMenuItem *Records1;
        TMenuItem *Configuracion1;
        TMenuItem *Salir1;
        TMediaPlayer *MediaPlayer1;
        void __fastcall NuevoJuegoButtonClick(TObject *Sender);
        void __fastcall Image2Click(TObject *Sender);
        void __fastcall Image3Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Image4Click(TObject *Sender);
        void __fastcall Creditos1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall THomeForm(TComponent* Owner);
        Jugador jugadores[10];
        int nJugadores;
        int idImagenCelda1;
        int idImagenCelda2;
        int idImagenFicha1;
        int idImagenFicha2;
        void mostrarCreditos();
        void reproducirMusica();
        void detenerMusica();
};
//---------------------------------------------------------------------------
extern PACKAGE THomeForm *HomeForm;
//---------------------------------------------------------------------------
#endif
