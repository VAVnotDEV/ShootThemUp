// ShootThemUp Game. All Rights Reserverd

#include "STUGameModeBase.h"
#include "Player/STUBaseCharacter.h"
#include "Player/STUPlayerController.h"

ASTUGameModeBase::ASTUGameModeBase() 
{
    DefaultPawnClass = ASTUBaseCharacter::StaticClass();
    PlayerControllerClass = ASTUPlayerController::StaticClass();
  

}
