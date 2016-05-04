//---------------------------------------------------------------------------

#ifndef JuegoFormUnitH
#define JuegoFormUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ImgList.hpp>
#include <jpeg.hpp>
#include <Graphics.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TJuegoForm : public TForm
{
__published:	// IDE-managed Components
        TPaintBox *PaintBox1;
        TImageList *ImageListTablero;
        TImageList *ImageListFichas;
        TLabel *NombreJugador2Label;
        TLabel *Turno2Label;
        TLabel *PausadoLabel;
        TImage *Image1;
        TImage *InitButton;
        TMainMenu *MainMenu1;
        TLabel *NombreJugador1Label;
        TLabel *Turno1Label;
        TImage *Image2;
        TMenuItem *Juego1;
        TMenuItem *PausarReiniciar1;
        TMenuItem *FinalizarJuego1;
        TMenuItem *Salir1;
        TPaintBox *Avatar1;
        TPaintBox *Avatar2;
        TImageList *AvatarList;
        TMenuItem *Creditos1;
        void __fastcall InitButtonClick(TObject *Sender);
        void __fastcall PaintBox1MouseUp(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall Salir1Click(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall PausarReiniciar1Click(TObject *Sender);
        void __fastcall FinalizarJuego1Click(TObject *Sender);
        void __fastcall Creditos1Click(TObject *Sender);
private:	// User declarations
        int turnoJugador;
        bool fichaSeleccionada;
        int fichaSeleccionadaCorsI;
        int fichaSeleccionadaCorsJ;
        int nFichasJugador1;
        int nFichasJugador2;
        bool activo;
        int idJugador1;
        int idJugador2;
        int idAvatarJugador1;
        int idAvatarJugador2;

        void pintarCuadrosTablero();
        int getIdImagenFicha(int idFicha);
        int getIdImagenCelda(int celda);
        void iniciarMatriz();
        void pintarFichas();
        void iniciarJuego();
        void actualizarPantalla();
        int corsPantallaToJuegoCors(int cors);
        bool fichaPerteneceAlJugadorActual(int idFicha);
        bool seleccionarFicha(int i, int j);
        bool idFichaPerteneceAlJugadorActual(int idFicha);
        bool celdaPermitidaFichaBasica(int i, int j);
        bool moverFichaSeleccionada(int movi, int movj);
        void cambiarTurno();
        void eliminarFicha(int i, int j);
        void declararVictoria(int jugador);
        void moverFicha(int fromi, int fromj, int toi, int toj);
        AnsiString getNombreJugador(int jugador);
        void pausarJuego();
        void reanudarJuego();
        void resetearJuego();
        void declararEmpate();
        void finalizarJuego();
        void pintarAvatares();

        int matrizFichas[8][8];
public:     // User declarations
        __fastcall TJuegoForm(TComponent* Owner);
        void setJugadoresIds(int jugador1, int jugador2);
        void setAvataresIds(int idAvatarJugador1, int idAvatarJugador2);
};
//---------------------------------------------------------------------------
extern PACKAGE TJuegoForm *JuegoForm;
//---------------------------------------------------------------------------
#endif
