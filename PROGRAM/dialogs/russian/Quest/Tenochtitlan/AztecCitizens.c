
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		//------------------------ Мешитли ------------------------
		case "AztecFT":
			dialog.text = "О-о, белый человек снова к нам пришел? "+ GetSexPhrase("","Да еще и женщина? ") +"Я видел, как ты ш"+ GetSexPhrase("ел","ла") +" по дамбе.";
			link.l1 = "Приветствую аборигена! Меня зовут капитан " + GetFullName(pchar) + ". А как твое имя?";
			link.l1.go = "AztecFT_1";
		break;
		case "AztecFT_1":
			dialog.text = "Мешитли.";
			link.l1 = "Ты здесь живешь, Мешитли? А кто еще кроме тебя здесь есть?";
			link.l1.go = "AztecFT_2";
		break;
		case "AztecFT_2":
			dialog.text = "Мой брат Ауисотль.";
			link.l1 = "Хе, да я смотрю, ты вполне нормальный ацтек. Стыдно сказать, но мне тут один раскрашенный и разряженный в пух индеец такого наговорил! На берегу там стоит, Монтесума зовут...";
			link.l1.go = "AztecFT_3";
		break;
		case "AztecFT_3":
			dialog.text = "Тихо! Это тот, о котором здесь не говорят! Если ты будешь ходить по Теночтитлану и говорить о том, имя которого произносить нельзя, то Миктлантекутли разгневается и сделает тебя своим слугой раньше времени!";
			link.l1 = "Микт... Миктла... Эх, не могу выговорить! В общем, не тот ли это ваш бог, что мертвых воскрешает?";
			link.l1.go = "AztecFT_4";
		break;
		case "AztecFT_4":
			dialog.text = "Он самый. И советую тебе относится к нему с уважением. А лучше всего, принести ему жертву.";
			link.l1 = "Какую жертву?";
			link.l1.go = "AztecFT_5";
		break;
		case "AztecFT_5":
			dialog.text = "Как обычно - кровь плененных тобой воинов. Приводи их сюда, а потом иди с ними в жертвенный храм. Ты долж"+ GetSexPhrase("ен","на") +" вырезать сердце война, пока он еще жив, и кровью окропить жертвенный камень Миктлантекутли.";
			link.l1 = "Что-то как-то я не очень этого желаю...";
			link.l1.go = "AztecFT_6";
		break;
		case "AztecFT_6":
			dialog.text = "А-а, ну тогда тебе удачи не видеть здесь. Миктлантекутли будет смотреть за тобой, и возьмет тебя к себе.";
			link.l1 = "Ну, это мы еще посморим... Это сколько же вы воинов в жертвы приносите? Я слышал"+ GetSexPhrase("","а") +", что богов у вас много...";
			link.l1.go = "AztecFT_7";
		break;
		case "AztecFT_7":
			dialog.text = "Раньше было много, а сейчас только Миктлантекутли служим. Мы с братом воинов не пленим и жертву не приносим, потому что Миктлантекутли обещал нам свое покровительство и жизнь после смерти. Так что мы в городе работаем по-мелочи, даже оружия не держим.";
			link.l1 = "Прямо таки Миктлантекутли собственно персоной и пообщал? Хех, как были вы дикарями, так и остались. Что тот франт на берегу, имя которого не произносят, что вы с братцем здесь. Так я и поверил"+ GetSexPhrase("","а") +" в вашего Миктлантекутли. Ты скажи мне лучше, что здесь в вашем Теночтитлане интересного.";
			link.l1.go = "AztecFT_8";
		break;
		case "AztecFT_8":
			dialog.text = "Ничего особенного. Храм Великой Жизненной Силы - самое большое строение. В пирамидах по обеим сторонам от него находятся храмы 10 богов. Храм Белых Богов - это пирамида с круглой башней, прямо напротив Храма Великой Жизненной Силы. Купальни еще есть...";
			link.l1 = "Слушай, как бы мне пробраться в этот Великий Храм?";
			link.l1.go = "AztecFT_9";
		break;
		case "AztecFT_9":
			dialog.text = "Этого делать тебе не стоит. Мы с братом мешать не будем, но Миктлантекутли может запросто отправить за тобой своих воинов. Не говоря уже о том, что храмы охраняют его слуги - великие войны прошлого.";
			link.l1 = "Понятно... Ну что же, будь здоров, Мешитли. Пообщаюсь еще с твоим братом при случае.";
			link.l1.go = "AztecFT_10";
		break;
		case "AztecFT_10":
			dialog.text = "Он будет очень рад. Живых в Теночтитлане кроме нас никого не осталось, так что пришельцы нам интересны."+ GetSexPhrase(""," Особенно такие красивые.") +"";
			link.l1 = ""+ GetSexPhrase("Хм, понятно.","Ого, да ты еще и комплименты говорить умеешь!") +"";
			link.l1.go = "AztecFT_11";
		break;
		case "AztecFT_11":
			LAi_SetImmortal(sld, false);
			LAi_SetCitizenType(npchar);
			NextDiag.TempNode = "Aztec1";
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		case "Aztec1":
			dialog.text = "Приветствую тебя, "+ GetSexPhrase("капитан","прекрасная скво") +" " + GetFullName(pchar) + ".";
			link.l1 = "И тебе привет, Мешитли";
			link.l1.go = "exit";
		break;

		case "Aztec1AF":
			dialog.text = ""+ GetSexPhrase("Белый капитан ходил","Прекрасная скво ходила") +" в Храм Великой Жизненной Силы и выжил"+ GetSexPhrase("","а") +"? Я очень удивлен...";
			link.l1 = "Что, не думал меня увидеть жив"+ GetSexPhrase("ым","ой") +"?";
			link.l1.go = "Aztec1AF_1";
		break;
		case "Aztec1AF_1":
			dialog.text = "Нет. Мы с братом поспорили, когда тебя возьмет Миктлантекутли. Никто не выиграл, ты остал"+ GetSexPhrase("ся жив","ась жива") +".";
			link.l1 = "Пообщал"+ GetSexPhrase("ся","ась") +" я с вашим Миктлантекутли. Очень познавательно.";
			link.l1.go = "Aztec1AF_2";
		break;
		case "Aztec1AF_2":
			dialog.text = "Ты счастлив"+ GetSexPhrase("ый, белый капитан","ая, прекрасная скво") +". Сам Миктлантекутли разговаривал с тобой и отпустил!";
			link.l1 = "Еще и череп какой-то дал нефритовый.";
			link.l1.go = "Aztec1AF_3";
		break;
		case "Aztec1AF_3":
			dialog.text = "Этот череп имеет власть над мертвыми, знай это! Тебе очень повезло, "+ GetSexPhrase("белый капитан","прекрасная скво") +".";
			link.l1 = "Я знаю. Ну ладно, бывай, Мешитли.";
			link.l1.go = "exit";
			NextDiag.TempNode = "Aztec1";
		break;


		//------------------------ Ауисотль ------------------------
		case "AztecFT2":
			dialog.text = "О-о, белый человек в Теночтитлане! "+ GetSexPhrase("","Да еще такая красивая скво! ") +"Очень интересно...";
			link.l1 = "Здравствуй, ацтек. Насколько я понимаю, тебя зовут Ауисотль.";
			link.l1.go = "AztecFT2_1";
		break;
		
		case "AztecFT2_1":
			dialog.text = "Да, это так. А кто ты так"+ GetSexPhrase("ой","ая") +"?";
			link.l1 = "Я капитан " + GetFullName(pchar) + ". Рад"+ GetSexPhrase("","а") +" познакомиться, так сказать, с местным жителем. С братом твоим, Мешитли, мы уже пообщались.";
			link.l1.go = "AztecFT2_2";
		break;
		case "AztecFT2_2":
			dialog.text = "Это хорошо. Скажи, "+ GetSexPhrase("белый капитан","прекрасная скво") +", что тебе нужно в нашем городе?";
			link.l1 = "Ищу кое-что. Слушай, может ты мне подскажешь, как проникнуть в Храм Великой Жизненной Силы? А еще мне надо в Храм Белых Богов...";
			link.l1.go = "AztecFT2_3";
		break;
		case "AztecFT2_3":
			dialog.text = "Ты в своем уме, "+ GetSexPhrase("белый капитан","прекрасная скво") +"? Миктлантекутли пожрет твое тело и душу!";
			link.l1 = "Я не боюсь. Если что-то знаешь, скажи.";
			link.l1.go = "AztecFT2_4";
		break;
		case "AztecFT2_4":
			dialog.text = "Ты "+ GetSexPhrase("глупый человек, белый капитан","очень красивая, белая скво, но и очень глупая") +". Надо пойти поспорить с братом на то, столько ты еще проживешь...";
			link.l1 = "И это все, что ты можешь сказать?";
			link.l1.go = "AztecFT2_5";
		break;
		case "AztecFT2_5":
			dialog.text = "Мы с братом - слуги великого Миктлантекутли, что ты хотел"+ GetSexPhrase("","а") +" от нас услышать?\nНо ты мне "+ GetSexPhrase("понравился, белый капитан, хоть и глупый","понравилась, белая скво, хоть и глупая") +". И скажу тебе, что в Храм Великой Жизненной Силы можно попасть не только через вход наверху пирамиды...";
			link.l1 = "Ну, спасибо и на этом, Ауисотль.";
			link.l1.go = "exit";
			NextDiag.TempNode = "Aztec2";
		break;

		case "Aztec2":
			dialog.text = "Ты еще "+ GetSexPhrase("живой, белый капитан","живая, прекрасная скво") +"?";
			link.l1 = "Как видишь, Ауисотль.";
			link.l1.go = "exit";
		break;

		case "Aztec2AF":
			dialog.text = ""+ GetSexPhrase("Белый капитан, ты ходил","Прекрасная скво, ты ходила") +" к Миктлантекутли?";
			link.l1 = "Ходил"+ GetSexPhrase("","а") +".";
			link.l1.go = "Aztec2AF_1";
		break;
		case "Aztec2AF_1":
			dialog.text = "И он не взял тебя своим слугой?";
			link.l1 = "Нет. Как видишь, я до сих пор жив"+ GetSexPhrase("","а") +", Ауисотль.";
			link.l1.go = "Aztec2AF_2";
		break;
		case "Aztec2AF_2":
			dialog.text = "О-о-о, ты великий человек, если сам Миктлантекутли отпустил тебя!";
			link.l1 = "Отпустил, да еще и череп нефритовый отдал!";
			link.l1.go = "Aztec2AF_3";
		break;
		case "Aztec2AF_3":
			dialog.text = "Череп воскрешения?! Не могу поверить\nАуисотль желает тебе удачи. Прощай, "+ GetSexPhrase("белый капитан","прекрасная скво") +".";
			link.l1 = "Прощай, Ауисотль.";
			link.l1.go = "exit";
			NextDiag.TempNode = "Aztec2AF_4";
		break;

		case "Aztec2AF_4":
			dialog.text = "Мы с братом будем "+ GetSexPhrase("помнить тебя, белый капитан","скучать по тебе, прекрасная скво") +".";
			link.l1 = "Всего хорошего.";
			link.l1.go = "exit";
		break;
	}
}
