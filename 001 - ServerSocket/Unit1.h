//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ScktComp.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TServerSocket *ServerSocket1;
    TMemo *Memo1;
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall ServerSocket1ClientConnect(TObject *Sender,
          TCustomWinSocket *Socket);
    void __fastcall ServerSocket1ClientDisconnect(TObject *Sender,
          TCustomWinSocket *Socket);
    void __fastcall ServerSocket1ClientRead(TObject *Sender,
          TCustomWinSocket *Socket);
    void __fastcall ServerSocket1ClientError(TObject *Sender,
          TCustomWinSocket *Socket, TErrorEvent ErrorEvent,
          int &ErrorCode);
    void __fastcall ServerSocket1Accept(TObject *Sender,
          TCustomWinSocket *Socket);
private:	// User declarations
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
    void __fastcall SendToAll(AnsiString Msg);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
