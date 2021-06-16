program DelphiTest;

uses
  Vcl.Forms,
  DelphiTestForm in 'DelphiTestForm.pas' {DelphiTestFrm};

{$R *.res}

begin
  Application.Initialize;
  Application.MainFormOnTaskbar := True;
  Application.CreateForm(TDelphiTestFrm, DelphiTestFrm);
  Application.Run;
end.
