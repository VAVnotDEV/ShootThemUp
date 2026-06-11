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

	FOnDeath OnDeath;
    FOnHealthChanged OnHealthChanged;
    
    UFUNCTION(BlueprintCallable)
    bool IsDead() const { return FMath::IsNearlyZero(Health); }
    
	float GetHealth() const { return Health; }

protected:
	virtual void BeginPlay() override;
   
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Health", meta = (ClampMin = "0.0", ClampMax = "1000.0"))
	float MaxHealth = 100.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Heal")
    bool bAutoHeal = false;

    UPROPERTY(EditDefaultsOnly, Category = "Heal", meta = (EditCondition = "bAutoHeal"))
    float HealUpdateTimer = 0.3f;

    UPROPERTY(EditDefaultsOnly, Category = "Heal", meta = (EditCondition = "bAutoHeal"))
    float HealDelay = 3.0f;

    UPROPERTY(EditDefaultsOnly, Category = "Heal", meta = (EditCondition = "bAutoHeal"))
    float HealModifier = 1.0f;
	
    float Health = 0.0f;

	FTimerHandle HealTimerHandle;
   
	UFUNCTION()
    void OnTakeAnyDamage(
       AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);
   
    void SetHealth(float NewHealth);
   
    void HealUpdate();


};
 