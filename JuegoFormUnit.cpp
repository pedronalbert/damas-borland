//---------------------------------------------------------------------------

#include <vcl.h>
#include <math.h>
#pragma hdrstop

#include "JuegoFormUnit.h"
#include "HomeFormUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TJuegoForm *JuegoForm;
#define IDIMAGENFICHASELEC 10
#define ANCHOJUEGO 50
#define NCOLORES_FICHA 5
//---------------------------------------------------------------------------
__fastcall TJuegoForm::TJuegoForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void TJuegoForm::pintarCuadrosTablero() {
  int i,j;
  int idTablero1 = this->getIdImagenCelda(1);
  int idTablero2 = this->getIdImagenCelda(2);

  for(i = 0; i < 8; i++) {
    for(j = 0; j < 8; j++) {
      if (i%2 == 0) {
        if(j%2 == 0) {
          ImageListTablero->Draw(PaintBox1->Canvas, j*ANCHOJUEGO, i*ANCHOJUEGO, idTablero1, true);
        } else {
          ImageListTablero->Draw(PaintBox1->Canvas, j*ANCHOJUEGO, i*ANCHOJUEGO, idTablero2, true);
        }
      } else {
        if(j%2 == 0) {
          ImageListTablero->Draw(PaintBox1->Canvas, j*ANCHOJUEGO, i*ANCHOJUEGO, idTablero2, true);
        } else {
          ImageListTablero->Draw(PaintBox1->Canvas, j*ANCHOJUEGO, i*ANCHOJUEGO, idTablero1, true);
        }        
      }
    }
  }
}

void TJuegoForm::pintarFichas() {
  int i, j, idImagen;

  for(i = 0; i < 8; i++) {
    for(j = 0; j < 8; j++) {
      if(this->matrizFichas[i][j] > 0) {
        idImagen = this->getIdImagenFicha(this->matrizFichas[i][j]);

        ImageListFichas->Draw(PaintBox1->Canvas, j*ANCHOJUEGO, i*ANCHOJUEGO, idImagen, true);
      }
    }
  }

  //ficha seleccionada
  if(this->fichaSeleccionada) {
    ImageListFichas->Draw(PaintBox1->Canvas, this->fichaSeleccionadaCorsJ*ANCHOJUEGO, this->fichaSeleccionadaCorsI*ANCHOJUEGO, IDIMAGENFICHASELEC, true);
  }
}

void TJuegoForm::iniciarMatriz() {
  int i,j;
  
  for(i = 0; i < 8; i++) {
    for(j = 0; j < 8; j++) {
      this->matrizFichas[i][j] = 0;
      
      if (i%2 == 0) {
        if(j%2 == 0 && i <= 2) {
          this->matrizFichas[i][j] = 2;
        }

        if(j%2 == 0 && i >= 5) {
          this->matrizFichas[i][j] = 1;
        }
      } else {
        if(j%2 != 0 && i <= 2) {
          this->matrizFichas[i][j] = 2;
        }

        if(j%2 != 0 && i >= 5) {
          this->matrizFichas[i][j] = 1;
        }
      }
    }
  }
}

int TJuegoForm::getIdImagenFicha(int idFicha) {
  if(idFicha == 1) {
    return HomeForm->idImagenFicha1;
  } else if(idFicha == 3){
    return HomeForm->idImagenFicha1 + NCOLORES_FICHA;
  } else if(idFicha == 2) {
    return HomeForm->idImagenFicha2;
  } else {
    return HomeForm->idImagenFicha2 + NCOLORES_FICHA;
  }
}

int TJuegoForm::getIdImagenCelda(int celda) {
  if(celda == 1) {
    return HomeForm->idImagenCelda1;
  } else {
    return HomeForm->idImagenCelda2;
  }
}
void __fastcall TJuegoForm::InitButtonClick(TObject *Sender)
{
  this->iniciarJuego();
}

void TJuegoForm::actualizarPantalla() {
  this->pintarCuadrosTablero();
  this->pintarFichas();
  this->pintarAvatares();
}

void TJuegoForm::iniciarJuego() {
  InitButton->Hide();
  PausadoLabel->Hide();
  this->iniciarMatriz();
  this->turnoJugador = 1;
  Turno1Label->Show();
  this->nFichasJugador1 = 12;
  this->nFichasJugador2 = 12;
  this->fichaSeleccionada = false;
  this->activo = true;
  this->actualizarPantalla();
}
//---------------------------------------------------------------------------
int TJuegoForm::corsPantallaToJuegoCors(int cors) {
  return floor(cors/ANCHOJUEGO);
}
//---------------------------------------------------------------------------

void __fastcall TJuegoForm::PaintBox1MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y) {
  int clickJ = this->corsPantallaToJuegoCors(X);
  int clickI = this->corsPantallaToJuegoCors(Y);
  int idFichaClicked = this->matrizFichas[clickI][clickJ];

  if (this->activo) {
    if (this->fichaSeleccionada) {
      if(idFichaClicked == 0) {
        if(this->moverFichaSeleccionada(clickI, clickJ)) {
          //Verificamos que los jugadores tengan fichas
          if (this->nFichasJugador1 == 0 || this->nFichasJugador2 == 0) {
            this->finalizarJuego();
          } else {
            this->cambiarTurno();
          }
        }
        
        this->fichaSeleccionada = false;
      } else {
        this->fichaSeleccionada = false;
      }

      this->actualizarPantalla();
    } else {
      if(idFichaClicked > 0) {
        this->seleccionarFicha(clickI, clickJ);
        this->actualizarPantalla();
      }
    }
  }
  
}

bool TJuegoForm::idFichaPerteneceAlJugadorActual(int idFicha) {
  if (this->turnoJugador == 1 && (idFicha == 1 || idFicha == 3)) {
    return true;
  } else if (this->turnoJugador == 2 && (idFicha == 2 || idFicha == 4)) {
    return true;
  }

  return false;
}

bool TJuegoForm::seleccionarFicha(int i, int j) {
  int idFicha = this->matrizFichas[i][j];

  if(this->idFichaPerteneceAlJugadorActual(idFicha)) {
    this->fichaSeleccionada = true;
    this->fichaSeleccionadaCorsI = i;
    this->fichaSeleccionadaCorsJ = j;

    return true;
  } else {
    ShowMessage("Esta ficha no te pertenece");

    return false;
  }
}

bool TJuegoForm::moverFichaSeleccionada(int movi, int movj) {
  int idFichaSelecionada = this->matrizFichas[this->fichaSeleccionadaCorsI][this->fichaSeleccionadaCorsJ];

  //Revisamos que sea una celda de juego
  if (!((movi%2 == 0 && movj%2 == 0) || (movi%2 != 0 && movj%2 != 0))) {
    return false;
  }

  //Si no es corona chequiamos el sentido
  if(idFichaSelecionada <= 2) {
    if (this->turnoJugador == 1) {
      if(movi > this->fichaSeleccionadaCorsI) {
        return false;
      }
    } else {
      if(movi < this->fichaSeleccionadaCorsI) {
        return false;
      }
    }  
  }
  
  int diffI = abs(this->fichaSeleccionadaCorsI - movi);
  int diffJ = abs(this->fichaSeleccionadaCorsJ - movj);

  if (diffI != diffJ || diffI > 2 || diffJ == 0) {
    return false;
  }

  if (diffI == 1) {
    //Movemos la ficha
    this->moverFicha(this->fichaSeleccionadaCorsI, this->fichaSeleccionadaCorsJ, movi, movj);

    return true;
  }

  if (diffI == 2) {
    int fichaContrariaCors[2];

    if (movi < this->fichaSeleccionadaCorsI) {
      fichaContrariaCors[0] = movi + 1;
    } else {
      fichaContrariaCors[0] = movi - 1;
    }

    if(movj > this->fichaSeleccionadaCorsJ) {
      fichaContrariaCors[1] = movj - 1;
    } else {
      fichaContrariaCors[1] = movj + 1;
    }

    //Chequiamos que la ficha contraria exista
    int idFichaContraria = this->matrizFichas[fichaContrariaCors[0]][fichaContrariaCors[1]];

    if(idFichaContraria != 0 && this->idFichaPerteneceAlJugadorActual(idFichaContraria) == false) {
      //Eliminamos la ficha muerta
      this->eliminarFicha(fichaContrariaCors[0], fichaContrariaCors[1]);
      //Le descontamos la ficha al otro jugador
      if (this->turnoJugador == 1) {
        this->nFichasJugador2--;
      } else {
        this->nFichasJugador1--;
      }
      //Movemos la ficha
      this->moverFicha(this->fichaSeleccionadaCorsI, this->fichaSeleccionadaCorsJ, movi, movj);

      return true;
    }
  }
}

void TJuegoForm::moverFicha(int fromi, int fromj, int toi, int toj) {
  //Movemos la ficha
  this->matrizFichas[toi][toj] = this->matrizFichas[fromi][fromj];
  //Eliminamos la ficha vieja
  this->matrizFichas[fromi][fromj] = 0;

  //Revisamos si es una coronación
  if(this->turnoJugador == 1 && toi == 0) {
    //Colocamos la coronacion
    this->matrizFichas[toi][toj] = 3;
  } else if(this->turnoJugador == 2 && toi == 7) {
    this->matrizFichas[toi][toj] = 4;
  }
}

void TJuegoForm::cambiarTurno() {
  if(this->turnoJugador == 1) {
    this->turnoJugador = 2;
    Turno1Label->Hide();
    Turno2Label->Show();
  } else {
    this->turnoJugador = 1;
    Turno2Label->Hide();
    Turno1Label->Show();
  }
}

void TJuegoForm::eliminarFicha(int i, int j) {
  this->matrizFichas[i][j] = 0;
}

void TJuegoForm::declararVictoria(int jugador) {
  AnsiString nickJugador;

  if(jugador == 1) {
    nickJugador = HomeForm->jugadores[this->idJugador1].nick;
    HomeForm->jugadores[this->idJugador1].ganadas++;
    HomeForm->jugadores[this->idJugador2].perdidas++;
  } else {
    nickJugador = HomeForm->jugadores[this->idJugador2].nick;
    HomeForm->jugadores[this->idJugador1].perdidas++;
    HomeForm->jugadores[this->idJugador2].ganadas++;
  }

  Turno1Label->Hide();
  Turno2Label->Hide();
  ShowMessage("El jugador: " + nickJugador + " ha ganado el juego!");

  this->activo = false;
  this->pintarCuadrosTablero();
  InitButton->Show();
}

AnsiString TJuegoForm::getNombreJugador(int jugador) {
  //TODO: Nombre del jugador
  if (jugador == 1) {
    return HomeForm->jugadores[this->idJugador1].nick;
  } else {
    return HomeForm->jugadores[this->idJugador2].nick;
  }
}

void TJuegoForm::setJugadoresIds(int idJugador1, int idJugador2) {
  this->idJugador1 = idJugador1;
  NombreJugador1Label->Caption = HomeForm->jugadores[idJugador1].nick;
  this->idJugador2 = idJugador2;
  NombreJugador2Label->Caption = HomeForm->jugadores[idJugador2].nick;
}
//---------------------------------------------------------------------------

void __fastcall TJuegoForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  HomeForm->Close();
}

void TJuegoForm::pausarJuego() {
  if(this->activo) {
    this->activo = false;
    PausadoLabel->Show();
  }
}

void TJuegoForm::reanudarJuego() {
  if(this->activo == false) {
    this->activo = true;
    PausadoLabel->Hide();
    this->actualizarPantalla();
  }
}

void __fastcall TJuegoForm::Salir1Click(TObject *Sender)
{
  if (this->activo) {
    this->finalizarJuego();
  }
  HomeForm->Show();
  JuegoForm->Hide();
}

void TJuegoForm::resetearJuego() {
  this->activo = false;
  InitButton->Show();
  PausadoLabel->Hide();
  Turno1Label->Hide();
  Turno2Label->Hide();
  PaintBox1->Repaint();

}
//---------------------------------------------------------------------------


void __fastcall TJuegoForm::FormShow(TObject *Sender)
{
  this->resetearJuego();        
}

void TJuegoForm::declararEmpate() {
  HomeForm->jugadores[this->idJugador1].empatadas++;
  HomeForm->jugadores[this->idJugador2].empatadas++;

  Turno1Label->Hide();
  Turno2Label->Hide();
  ShowMessage("Los jugadoes han empatado el juego!");

  this->activo = false;
  this->pintarCuadrosTablero();
  InitButton->Show();
}

void TJuegoForm::finalizarJuego() {
  if (this->nFichasJugador1 > this->nFichasJugador2) {
    this->declararVictoria(1);
  } else if (this->nFichasJugador2 > this->nFichasJugador1) {
    this->declararVictoria(2);
  } else {
    this->declararEmpate();
  }
}
//---------------------------------------------------------------------------

void __fastcall TJuegoForm::PausarReiniciar1Click(TObject *Sender)
{
  if (this->activo) {
    this->pausarJuego();
  } else {
    this->reanudarJuego();
  }
}
//---------------------------------------------------------------------------

void __fastcall TJuegoForm::FinalizarJuego1Click(TObject *Sender)
{
  this->finalizarJuego();        
}

void TJuegoForm::setAvataresIds(int idAvatarJugador1, int idAvatarJugador2) {
  this->idAvatarJugador1 = idAvatarJugador1;
  this->idAvatarJugador2 = idAvatarJugador2;
}

void TJuegoForm::pintarAvatares() {
  AvatarList->Draw(Avatar1->Canvas, 0, 0, this->idAvatarJugador1, true);
  AvatarList->Draw(Avatar2->Canvas, 0, 0, this->idAvatarJugador2, true);
}
//---------------------------------------------------------------------------

void __fastcall TJuegoForm::Creditos1Click(TObject *Sender)
{
  HomeForm->mostrarCreditos();        
}
//---------------------------------------------------------------------------

