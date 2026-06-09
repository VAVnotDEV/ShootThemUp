// ShootThemUp Game. All Rights Reserverd

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "STUHealthComponent.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnDeath)
DECLARE_MULTICAST_DELEGATE_OneParam(FOnHealthChanged, float)

    UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SHOOTTHEMUP_API USTUHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	USTUHealthComponent();

	float GetHealth() const { return Health; }

	UFUNCTION(BlueprintCallable)
    bool IsDead() const { return Health <= 0.0f; }


	FOnDeath OnDeath;
    FOnHealthChanged OnHealthChanged;

protected:
	virtual void BeginPlay() override;
    UPROPERTY(EditDEfaultsOnly, BlueprintReadWrite, Category = "Health", meta = (ClampMin = "0.0", ClampMax = "1000.0"))
	float MaxHealth = 100.0f;
	
private:
	float Health = 0.0f;

	UPROPERTY(EditDEfaultsOnly, BlueprintReadWrite, Category = "Heal")
	bool bAutoHeal = false;
    UPROPERTY(EditDEfaultsOnly, BlueprintReadWrite, Category = "Heal")
	float HealUpdateTimer = 0.3f;
    UPROPERTY(EditDEfaultsOnly, BlueprintReadWrite, Category = "Heal")
	float HealDelay = 3.0f;
    UPROPERTY(EditDEfaultsOnly, BlueprintReadWrite, Category = "Heal")
	float HealModifier = 1.0f;

   UFUNCTION()
   void OnTakeAnyDamage(
       AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);
};
 