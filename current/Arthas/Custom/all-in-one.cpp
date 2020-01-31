/*

Full NPC with lots of menus, and options.
By: Blue
Rewritten by: LordPsyan http://www.realmsofwarcraft.com
Version: 4.0a // Will be updated

*-------------------------------------
*
             DEFINES
*
*------------------------------------*/
#include "LordPsyan.h"

// Whisps
#define notvip "You are not a VIP Member. Check website for details."
#define yesvip "Welcome honored VIP Member"
#define skillsmaxed "You skills are now maxed"
#define votewhisper "Time to vote"
#define donationhelp "Please donate to help the realm"
#define normalhelp "If you need help, ask."
#define ingamehelp "If you need help ingame, contact a GM"
#define nosickness "You do not have Ressurection Sickness"
#define nopet "You do not have a pet"
#define welcome "Greetings Traveler. How can I help you?"

// TOKEN ------------------------
#define tokenbuy "I want to buy a %Servername% token."
#define tokenchange "I want to change a %tokenname% to a %tokenname2%."

// mails
#define moneymail 60003

// items
#define token1 99999 // Token1 entry number (swap).
#define token2 99998 // Token2 entry number (receive).
#define vasarolhatotoken 100000 // Available as token -.-

// Trainers
#define dk        28474
#define wari    914
#define pala    23128
#define sami    17204
#define hunta    5115
#define rogue    4584
#define dudu    16655
#define mage    28958
#define priest    4090
#define lock    23534

//Teleport
#define HMX -1854.022095f
#define HMY -5412.382324f
#define HMZ -12.428071f
#define HMM 530

#define AMX -1854.022095f
#define AMY -5412.382324f
#define AMZ -12.428071f
#define AMM 530

//Levelroad Teleport
#define HLX 4613.816406f
#define HLY -3589.231689f
#define HLZ 994.164185f
#define HLM 1

#define ALX 6899.129883f
#define ALY -2298.679932f
#define ALZ 588.010986f
#define ALM 1
// DO NOT EDIT HERE //
#define SPELL_ID_PASSIVE_RESURRECTION_SICKNESS  15007



class npc_all : public CreatureScript
{
public:
    npc_all() : CreatureScript("npc_all") { }

static bool OnGossipHello(Player *player, Creature *_Creature)

{
    _Creature->Whisper(welcome, LANG_UNIVERSAL, player);


    AddGossipItemFor(player, 0, "[Menu]Morph", GOSSIP_SENDER_MAIN, 100);
    AddGossipItemFor(player, 0, "[Menu]Teleport", GOSSIP_SENDER_MAIN, 101); // 1.1
    AddGossipItemFor(player, 0, "[Menu]Set My Skills to Maximum", GOSSIP_SENDER_MAIN, 102);
    AddGossipItemFor(player, 0, "[Menu]Trainers", GOSSIP_SENDER_MAIN, 103); // 1.2
    AddGossipItemFor(player, 0, "[Menu]Server Menus", GOSSIP_SENDER_MAIN, 104);
    AddGossipItemFor(player, 0, "[Menu]Funny Things", GOSSIP_SENDER_MAIN, 105);
    AddGossipItemFor(player, 0, "[Menu]Announcer", GOSSIP_SENDER_MAIN, 106);
    //AddGossipItemFor(player, 0, "[Menu]Token Buy", GOSSIP_SENDER_MAIN, 107); // Not configured
    //AddGossipItemFor(player, 0, "[Menu]Token Change", GOSSIP_SENDER_MAIN, 108); // Not Configured
    //AddGossipItemFor(player, 0, "[Menu]Vote", GOSSIP_SENDER_MAIN, 113); // Not Configured
    AddGossipItemFor(player, 0, "[Menu]Remove Sickness", GOSSIP_SENDER_MAIN, 120);
    AddGossipItemFor(player, 0, "[Menu]Reset Talent Points", GOSSIP_SENDER_MAIN, 121);
    //AddGossipItemFor(player, 0, "[Menu]Reputations", GOSSIP_SENDER_MAIN, 123); // Not Configured. No Data.
    //AddGossipItemFor(player, 0, "[Menu]Titles", GOSSIP_SENDER_MAIN, 124); // No Data for adding titles.
    AddGossipItemFor(player, 0, "[Menu]Buffs", GOSSIP_SENDER_MAIN, 125);


        if (player->GetSession()->GetSecurity() >= 1)
        {
        _Creature->Whisper(yesvip, LANG_UNIVERSAL, player);
        AddGossipItemFor(player, 0, "[Menu]Battleground Control", GOSSIP_SENDER_MAIN, 109);
        //AddGossipItemFor(player, 0, "[Menu]Vip functions", GOSSIP_SENDER_MAIN, 110);// No Data.
        } else { _Creature->Whisper(notvip, LANG_UNIVERSAL, player); }


    SendGossipMenuFor(player, 1, _Creature->GetGUID());
    return true;
}

void static SendDefaultMenu(Player *player, Creature *_Creature, uint32 action)
{

// Not allow in combat
if (player->IsInCombat())
{
    CloseGossipMenuFor(player);
    _Creature->Say("You are in combat!", LANG_UNIVERSAL);
    return;
}

    switch(action)

    {

        //////////////// MAIN MENUS -> Normal Menus //////////////////
    case 100: // Morphs
        AddGossipItemFor(player, 0, "Illidan", GOSSIP_SENDER_MAIN, 500);
        AddGossipItemFor(player, 0, "Kil'jaeden", GOSSIP_SENDER_MAIN, 501);
        AddGossipItemFor(player, 0, "Akama", GOSSIP_SENDER_MAIN, 502);
        AddGossipItemFor(player, 0, "Deathknight", GOSSIP_SENDER_MAIN, 503);
        AddGossipItemFor(player, 0, "Tauren", GOSSIP_SENDER_MAIN, 504);
        AddGossipItemFor(player, 0, "Undead", GOSSIP_SENDER_MAIN, 505);
        AddGossipItemFor(player, 0, "Human", GOSSIP_SENDER_MAIN, 506);
        AddGossipItemFor(player, 0, "Lich King", GOSSIP_SENDER_MAIN, 507);
        AddGossipItemFor(player, 0, "Tirion", GOSSIP_SENDER_MAIN, 508);
        AddGossipItemFor(player, 0, "Uther Lightbringer", GOSSIP_SENDER_MAIN, 509);
        AddGossipItemFor(player, 0, "Arthas", GOSSIP_SENDER_MAIN, 510);
        ///////////// From SPGM
        AddGossipItemFor(player, 4, "Algalon", GOSSIP_SENDER_MAIN, 711);
        AddGossipItemFor(player, 4, "Doomwalker", GOSSIP_SENDER_MAIN, 712);
        AddGossipItemFor(player, 4, "Doomlord kazzak", GOSSIP_SENDER_MAIN, 713);
        AddGossipItemFor(player, 4, "Onyxia", GOSSIP_SENDER_MAIN, 714);
        AddGossipItemFor(player, 4, "Thaddius", GOSSIP_SENDER_MAIN, 715);
        AddGossipItemFor(player, 4, "Gluth", GOSSIP_SENDER_MAIN, 716);
        AddGossipItemFor(player, 4, "Maexxna", GOSSIP_SENDER_MAIN, 717);
        AddGossipItemFor(player, 4, "Sapphiron", GOSSIP_SENDER_MAIN, 718);
        AddGossipItemFor(player, 4, "Noth The Plaguebringer", GOSSIP_SENDER_MAIN, 719);
        AddGossipItemFor(player, 4, "Kel'Thuzad", GOSSIP_SENDER_MAIN, 720);
        AddGossipItemFor(player, 4, "Kael'thas Sunstrider", GOSSIP_SENDER_MAIN, 721);
        AddGossipItemFor(player, 4, "C'thun", GOSSIP_SENDER_MAIN, 722);
        AddGossipItemFor(player, 4, "Thrall", GOSSIP_SENDER_MAIN, 723);
        SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE,_Creature->GetGUID());
    break;


    case 101: // Teleport
        AddGossipItemFor(player, 1, "Raids/Dungeons", GOSSIP_SENDER_MAIN, 600);
        AddGossipItemFor(player, 1, "Cities", GOSSIP_SENDER_MAIN, 601);
        //AddGossipItemFor(player, 1, "Fun places", GOSSIP_SENDER_MAIN, 602); // Only For Funservers. Not Configured
        //AddGossipItemFor(player, 1, "Events", GOSSIP_SENDER_MAIN, 603); // Funservers. Not Configured
        AddGossipItemFor(player, 1, "Areas", GOSSIP_SENDER_MAIN, 604);
        SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE,_Creature->GetGUID());
        break;

    case 102: // Skill maxer
        CloseGossipMenuFor(player);
        player->UpdateWeaponsSkillsToMaxSkillsForLevel();
        _Creature->Whisper(skillsmaxed, LANG_UNIVERSAL, player);
        break;

    case 103: // Trainers

        AddGossipItemFor(player, 1, "Prof Trainer", GOSSIP_SENDER_MAIN, 800);
        AddGossipItemFor(player, 1, "Class Trainer", GOSSIP_SENDER_MAIN, 801);
        //AddGossipItemFor(player, 1, "Weapon Trainer", GOSSIP_SENDER_MAIN, 802); // Not Configured.
        AddGossipItemFor(player, 1, "Mount Trainer", GOSSIP_SENDER_MAIN, 803);
        SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE,_Creature->GetGUID());
        break;

    case 104: // Server Menus
        //AddGossipItemFor(player, 1, "Help! I've got hacked (Lock Account)", GOSSIP_SENDER_MAIN, 900);
        AddGossipItemFor(player, 0, "Report Lagg", GOSSIP_SENDER_MAIN, 901);
        AddGossipItemFor(player, 0, "Help", GOSSIP_SENDER_MAIN, 903);
        SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE,_Creature->GetGUID());
        break;

    case 105: // Funny Things, Need some more
        AddGossipItemFor(player, 0, "Money", GOSSIP_SENDER_MAIN, 1000); // DELETE THIS IF YOU DONT WANT PLAYERS TO GET MONEY
        AddGossipItemFor(player, 0, "Drunk", GOSSIP_SENDER_MAIN, 1001);
        AddGossipItemFor(player, 0, "Sober", GOSSIP_SENDER_MAIN, 1002);
        SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE,_Creature->GetGUID());
        break;

    case 106: // Announcer Part
        AddGossipItemFor(player, 0, "Join Warsong Guilch!", GOSSIP_SENDER_MAIN, 1100);
        AddGossipItemFor(player, 0, "Join Arathi Basin!", GOSSIP_SENDER_MAIN, 1101);
        AddGossipItemFor(player, 0, "Join Wintergrasp!", GOSSIP_SENDER_MAIN, 1102);
        AddGossipItemFor(player, 0, "Join Strand of the ancients!", GOSSIP_SENDER_MAIN, 1103);
        AddGossipItemFor(player, 0, "Join Alterac Valley!", GOSSIP_SENDER_MAIN, 1104);
        AddGossipItemFor(player, 0, "Join Random Battleground!", GOSSIP_SENDER_MAIN, 1105);
        AddGossipItemFor(player, 0, "Join Arena 2v2!", GOSSIP_SENDER_MAIN, 1106);
        AddGossipItemFor(player, 0, "Join Arena 3v3!", GOSSIP_SENDER_MAIN, 1107);
        AddGossipItemFor(player, 0, "Join Arena 5v5!", GOSSIP_SENDER_MAIN, 1108);
        AddGossipItemFor(player, 0, "Join Eye of the Storm!", GOSSIP_SENDER_MAIN, 1109);
        SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE,_Creature->GetGUID());
        break;
    case 107: // Token -> BUY
        AddGossipItemFor(player, 0, tokenbuy, GOSSIP_SENDER_MAIN, 1200);
        SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE,_Creature->GetGUID());
        break;

    case 108: // Token ->Change
        AddGossipItemFor(player, 0, tokenchange, GOSSIP_SENDER_MAIN, 1300);
        SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE,_Creature->GetGUID());
        break;

    case 109: // Battleground function
        AddGossipItemFor(player, 0, "WSG 100%", GOSSIP_SENDER_MAIN, 1400);
        AddGossipItemFor(player, 0, "EOTS 100%", GOSSIP_SENDER_MAIN, 1401);
        AddGossipItemFor(player, 0, "AB 100%", GOSSIP_SENDER_MAIN, 1402);
        AddGossipItemFor(player, 0, "SOTA 100%", GOSSIP_SENDER_MAIN, 1403);
        AddGossipItemFor(player, 0, "AV 100%", GOSSIP_SENDER_MAIN, 1404); // LOL!
        SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE,_Creature->GetGUID());
        break;

    case 110: // VIP Functions, from another script(by me :D)
        AddGossipItemFor(player, 0, "Repair", GOSSIP_SENDER_MAIN, 1500);
        AddGossipItemFor(player, 0, "Nyugit szeretnék", GOSSIP_SENDER_MAIN, 1501);
        AddGossipItemFor(player, 0, "Surgery", GOSSIP_SENDER_MAIN, 1502);
        AddGossipItemFor(player, 0, "Faction change", GOSSIP_SENDER_MAIN, 1503);
        AddGossipItemFor(player, 0, "Race Change", GOSSIP_SENDER_MAIN, 1504);
        //AddGossipItemFor(player, 0, "Move?", GOSSIP_SENDER_MAIN, 1505); Not yet implemented
        AddGossipItemFor(player, 0, "Name Change", GOSSIP_SENDER_MAIN, 1506);
        AddGossipItemFor(player, 0, "Save Character", GOSSIP_SENDER_MAIN, 1507);
        AddGossipItemFor(player, 0, "Mailbox", GOSSIP_SENDER_MAIN, 1508);
        SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE,_Creature->GetGUID());
        break;

    case 111: // VOte
        _Creature->Whisper(votewhisper, LANG_UNIVERSAL, player);
        AddGossipItemFor(player, 0, "1 - %VOTE1%", GOSSIP_SENDER_MAIN, 1600);
        AddGossipItemFor(player, 0, "2 - %VOTE2%", GOSSIP_SENDER_MAIN, 1601);
        AddGossipItemFor(player, 0, "3 - %VOTE3%", GOSSIP_SENDER_MAIN, 1602);
        AddGossipItemFor(player, 0, "4 - %VOTE4%", GOSSIP_SENDER_MAIN, 1603);
        SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE,_Creature->GetGUID());
        break;

    case 124: // Titles, Not Ready Yet!
        AddGossipItemFor(player, 0, "Jenkins", GOSSIP_SENDER_MAIN, 3000);
        AddGossipItemFor(player, 0, "Loremaster", GOSSIP_SENDER_MAIN, 3001);
        AddGossipItemFor(player, 0, "the Seeker", GOSSIP_SENDER_MAIN, 3002);
        AddGossipItemFor(player, 0, "the Argent Defender", GOSSIP_SENDER_MAIN, 3003);
        AddGossipItemFor(player, 0, "Bane of the Fallen King", GOSSIP_SENDER_MAIN, 3004);
        AddGossipItemFor(player, 0, "Champion of the Frozen Wastes", GOSSIP_SENDER_MAIN, 3005);
        AddGossipItemFor(player, 0, "Champion of the Naaru", GOSSIP_SENDER_MAIN, 3006);
        AddGossipItemFor(player, 0, "Conqueror of Naxxramas", GOSSIP_SENDER_MAIN, 3007);
        AddGossipItemFor(player, 0, "Conqueror of Ulduar", GOSSIP_SENDER_MAIN, 3008);
        AddGossipItemFor(player, 0, "Hand of A'dal", GOSSIP_SENDER_MAIN, 3009);
        AddGossipItemFor(player, 0, "the Immortal", GOSSIP_SENDER_MAIN, 3010);
        AddGossipItemFor(player, 0, "the Patient", GOSSIP_SENDER_MAIN, 3011);
        AddGossipItemFor(player, 0, "the Undying", GOSSIP_SENDER_MAIN, 3012);
        AddGossipItemFor(player, 0, "Ambassador", GOSSIP_SENDER_MAIN, 3013);
        AddGossipItemFor(player, 0, "Bloodsail Admiral", GOSSIP_SENDER_MAIN, 3014);
        AddGossipItemFor(player, 0, "Crusader", GOSSIP_SENDER_MAIN, 3015);
        AddGossipItemFor(player, 0, "the Diplomat", GOSSIP_SENDER_MAIN, 3016);
        AddGossipItemFor(player, 0, "the Exalted", GOSSIP_SENDER_MAIN, 3017);
        SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE,_Creature->GetGUID());
        break;
        /// Buffer part
    case 125: // buffer
        AddGossipItemFor(player, 0, "[Buff]Power Word: Fortitude, Rank 8", GOSSIP_SENDER_MAIN, 4000);
        AddGossipItemFor(player, 0, "[Buff]Greater Blessing of Kings", GOSSIP_SENDER_MAIN, 4001);
        AddGossipItemFor(player, 0, "[Buff]Greater Bleesing of Mights", GOSSIP_SENDER_MAIN,4002);
        AddGossipItemFor(player, 0, "[Buff]Greater Blessing of Wisdom", GOSSIP_SENDER_MAIN, 4003);
        AddGossipItemFor(player, 0, "[Buff]Mark of the Wild, Rank 9", GOSSIP_SENDER_MAIN, 4004);
        AddGossipItemFor(player, 0, "[Buff]Arcane Intellect, Rank 7", GOSSIP_SENDER_MAIN, 4005);
        AddGossipItemFor(player, 0, "[Buff]Soul Stone", GOSSIP_SENDER_MAIN, 4006);
        AddGossipItemFor(player, 0, "[Buff]Thorns, Rank 8", GOSSIP_SENDER_MAIN, 4007);
        AddGossipItemFor(player, 0, "[Buff]Divine Spirit, Rank 8", GOSSIP_SENDER_MAIN, 4008);
        AddGossipItemFor(player, 0, "[Buff]Shadow Protection, Rank 5", GOSSIP_SENDER_MAIN, 4009);
        SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE,_Creature->GetGUID());
         break;

    case 4000:
        CloseGossipMenuFor(player);
        _Creature->CastSpell(player, 48161, false); // target, spellid, triggered-e
        break;

        case 4001:
        CloseGossipMenuFor(player);
        _Creature->CastSpell(player, 25898, false);
        break;

        case 4002:
        CloseGossipMenuFor(player);
        _Creature->CastSpell(player, 48934, false);
        break;

        case 4003:
        CloseGossipMenuFor(player);
        _Creature->CastSpell(player, 48938, false);
        break;

        case 4004:
        CloseGossipMenuFor(player);
        _Creature->CastSpell(player, 48469, false);
        break;

        case 4005:
        CloseGossipMenuFor(player);
        _Creature->CastSpell(player, 42995, false);
        break;

        case 4006:
        CloseGossipMenuFor(player);
        _Creature->CastSpell(player, 47883, false);
        break;

        case 4007:
        CloseGossipMenuFor(player);
        _Creature->CastSpell(player, 53307, false);
        break;

        case 4008:
        CloseGossipMenuFor(player);
        _Creature->CastSpell(player, 48073, false);
        break;

        case 4009:
        CloseGossipMenuFor(player);
        _Creature->CastSpell(player, 48169, false);
        break;


        /////////// NORMAL MENUS -> ACTION OR MENU



        ///-- Server Menus part start --///
        /*case 900: // Hacked
        // Closes the account
        LoginDatabase.PQuery("UPDATE `account` SET `locked`=1 WHERE `id`='%s'", player->GetSession()->GetAccountId());
        LoginDatabase.PQuery("INSERT INTO `hacked` (`charname`) VALUES ('%s'", player); // Report it to the DB.
        break;
*/
        case 901: // Report lagg
        /*CloseGossipMenuFor(player);
        _Creature->Whisper(('%s', player->GetSession()->GetAccountId()), player);
        LoginDatabase.PExecute("INSERT INTO `lagreports` (`account`) VALUES ('%s'", player->GetSession()->GetAccountId());
        _Creature->Whisper("Lagg report done.", LANG_UNIVERSAL, player);*/
        break;

        case 902: // Help
        AddGossipItemFor(player, 0, "Donation Help", GOSSIP_SENDER_MAIN, 1700);
        AddGossipItemFor(player, 0, "Ingame Help", GOSSIP_SENDER_MAIN, 1701);
        AddGossipItemFor(player, 0, "Normal Help", GOSSIP_SENDER_MAIN, 1702);
        SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE,_Creature->GetGUID());
        break;

        case 1700: // Donation Help
        CloseGossipMenuFor(player);
        _Creature->Whisper("Donations can be done on www.realmsofwarcraft.com", LANG_UNIVERSAL, player);
        break;

        case 1701: // INGAME HELP
        CloseGossipMenuFor(player);
        _Creature->Whisper("Contact a GM for help", LANG_UNIVERSAL, player);
        break;

        case 1702: // Normal Help
        CloseGossipMenuFor(player);
        _Creature->Whisper("Helpful information can be found on www.realmsofwarcraft.com", LANG_UNIVERSAL, player);
        break;
        /// -- Server Menus part End -- ///

        /// -- Funny Things Menu Start -- /// money drunk sober

        case 1000: // Money
        CloseGossipMenuFor(player);
        player->GetMail(moneymail);
        _Creature->Whisper("Check your mailbox.", LANG_UNIVERSAL, player);
        break;

        case 1001: // Drunk
        CloseGossipMenuFor(player);
        player->CastSpell(player, 46876, false);
        break;

        case 1002: // Sober
        CloseGossipMenuFor(player);
        player->SetDrunkValue(0, 9);
        break;
        /// -- Funny Things Menu End -- ///

        /// -- Announcer Part Start -- ///

        case 1100:
        CloseGossipMenuFor(player);
        ChatHandler(player->GetSession()).PSendSysMessage(LANG_WSG);
        break;

        case 1101:
        CloseGossipMenuFor(player);
        ChatHandler(player->GetSession()).SendSysMessage(LANG_AB);
        break;

        case 1102:
        CloseGossipMenuFor(player);
        ChatHandler(player->GetSession()).SendSysMessage(LANG_WG);
        break;

        case 1103:
        CloseGossipMenuFor(player);
        ChatHandler(player->GetSession()).SendSysMessage(LANG_SOTA);
        break;

        case 1104:
        CloseGossipMenuFor(player);
        ChatHandler(player->GetSession()).SendSysMessage(LANG_AV);
        break;

        case 1105:
        CloseGossipMenuFor(player);
        ChatHandler(player->GetSession()).SendSysMessage(LANG_RANDOM);
        break;

        case 1106:
        CloseGossipMenuFor(player);
        ChatHandler(player->GetSession()).SendSysMessage(LANG_ARENA_1);
        break;

        case 1107:
        CloseGossipMenuFor(player);
        ChatHandler(player->GetSession()).SendSysMessage(LANG_ARENA_2);
        break;

        case 1108:
        CloseGossipMenuFor(player);
        ChatHandler(player->GetSession()).SendSysMessage(LANG_ARENA_3);
        break;

        case 1109:
        CloseGossipMenuFor(player);
        ChatHandler(player->GetSession()).SendSysMessage(LANG_EOTS);
        break;

        /// -- Announcer part end -- ///

        /////////////////////////////////
        //        BREAK           //
        //////////////////////////////////
        //////////////////////////////////

    /*************************************************************************/

        /// -- Morph Part Start -- ///

               case 500:
        CloseGossipMenuFor(player);
        player->SetDisplayId(21135);
        break;

        case 501:
        CloseGossipMenuFor(player);
        player->SetDisplayId(23200);
        break;

        case 502:
        CloseGossipMenuFor(player);
        player->SetDisplayId(20681);
        break;

        case 503:
        CloseGossipMenuFor(player);
        player->SetDisplayId(16508);
        break;

        case 504:
        CloseGossipMenuFor(player);
        player->SetDisplayId(17332);
        break;

        case 505:
        CloseGossipMenuFor(player);
        player->SetDisplayId(2789);
        break;

        case 506:
        CloseGossipMenuFor(player);
        player->SetDisplayId(16280);
        break;

        case 507:
        CloseGossipMenuFor(player);
        player->SetDisplayId(24191);
        break;

        case 508:
        CloseGossipMenuFor(player);
        player->SetDisplayId(22209);
        break;

        case 509:
        CloseGossipMenuFor(player);
        player->SetDisplayId(23889);
        break;

        case 510:
        CloseGossipMenuFor(player);
        player->SetDisplayId(24949);
        break;

        case 711: // Algalon
        CloseGossipMenuFor(player);
        player->SetDisplayId(28641);
        player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.2f);
        break;

        case 712: // Doomwalker
        CloseGossipMenuFor(player);
        player->SetDisplayId(16630);
        player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.1f);
        break;

        case 713: // Doomlord kazzak
        CloseGossipMenuFor(player);
        player->SetDisplayId(17887);
        player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.10f);
        break;

        case 714: // Onyxia
        CloseGossipMenuFor(player);
        player->SetDisplayId(8570);
        player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.1f);
        break;

        case 715: // Thaddius
        CloseGossipMenuFor(player);
        player->SetDisplayId(16137);
        player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.2f);
        break;

        case 716: // Gluth
        CloseGossipMenuFor(player);
        player->SetDisplayId(16064);
        player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.2f);
        break;

        case 717: // Maexxna
        CloseGossipMenuFor(player);
        player->SetDisplayId(15928);
        player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.15f);
        break;

        case 718: // Sapphiron
        CloseGossipMenuFor(player);
        player->SetDisplayId(16033);
        player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.1f);
        break;

        case 719: // Noth The Plaguebringer
        CloseGossipMenuFor(player);
        player->SetDisplayId(16590);
        player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.7f);
        break;

        case 720: // Kel'Thuzad
        CloseGossipMenuFor(player);
        player->SetDisplayId(15945);
        player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.2f);
        break;

        case 721: // Kael'thas Sunstrider
        CloseGossipMenuFor(player);
        player->SetDisplayId(20023);
        player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.5f);
        break;

        case 722: // C'thun
        CloseGossipMenuFor(player);
        player->SetDisplayId(15786);
        player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.1f);
        break;

        case 723: // Thrall
        CloseGossipMenuFor(player);
        player->SetDisplayId(4527);
        player->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.0f);
        break;

/// -- Morph Part End -- ///







/// -- Teleport Part Start -- ///
        case 600: // Raid dungeon , cities
        AddGossipItemFor(player, 0, "ICC", GOSSIP_SENDER_MAIN, 1900);
        AddGossipItemFor(player, 0, "Naxxramas", GOSSIP_SENDER_MAIN, 1901);
        AddGossipItemFor(player, 0, "Ulduar", GOSSIP_SENDER_MAIN, 1902);
        AddGossipItemFor(player, 0, "Nexus", GOSSIP_SENDER_MAIN, 1903);
        AddGossipItemFor(player, 0, "Argent Tournament Grounds", GOSSIP_SENDER_MAIN, 1904);
        AddGossipItemFor(player, 0, "Azjol-Nerub", GOSSIP_SENDER_MAIN, 1905);
        AddGossipItemFor(player, 0, "Drak' Tharon Keep", GOSSIP_SENDER_MAIN, 1906);
        AddGossipItemFor(player, 0, "Gundrak", GOSSIP_SENDER_MAIN, 1907);
        AddGossipItemFor(player, 0, "Utgarde Keep", GOSSIP_SENDER_MAIN, 1908);
        AddGossipItemFor(player, 0, "Utgarde Pinnacle", GOSSIP_SENDER_MAIN, 1909);
        AddGossipItemFor(player, 0, "Vault of Archavon", GOSSIP_SENDER_MAIN, 1910);
        AddGossipItemFor(player, 0, "Violet Hold", GOSSIP_SENDER_MAIN, 1911);
        SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE,_Creature->GetGUID());
        break;

        case 601: // Cities

        AddGossipItemFor(player, 0, "Teleport Stormwind", GOSSIP_SENDER_MAIN, 1800);
        AddGossipItemFor(player, 0, "Teleport Ironforge", GOSSIP_SENDER_MAIN, 1801);
        AddGossipItemFor(player, 0, "Teleport Darnassus", GOSSIP_SENDER_MAIN, 1802);
        AddGossipItemFor(player, 0, "Teleport Exodar", GOSSIP_SENDER_MAIN, 1803);
        AddGossipItemFor(player, 0, "Teleport Shattrath", GOSSIP_SENDER_MAIN, 1804);
        AddGossipItemFor(player, 0, "Teleport Dalaran", GOSSIP_SENDER_MAIN, 1805);
        AddGossipItemFor(player, 0, "Teleport Gurubashi Arena", GOSSIP_SENDER_MAIN, 1806);
        AddGossipItemFor(player, 0, "Teleport Orgrimmar", GOSSIP_SENDER_MAIN, 1807);
        AddGossipItemFor(player, 0, "Teleport Undercity", GOSSIP_SENDER_MAIN, 1808);
        AddGossipItemFor(player, 0, "Teleport Silvermoon", GOSSIP_SENDER_MAIN, 1809);
        AddGossipItemFor(player, 0, "Teleport Thunder Bluff", GOSSIP_SENDER_MAIN, 1810);
        AddGossipItemFor(player, 0, "Teleport Alliance Mall", GOSSIP_SENDER_MAIN, 5000);
        AddGossipItemFor(player, 0, "Teleport Alliance LevelRoad", GOSSIP_SENDER_MAIN, 9998);

        SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE,_Creature->GetGUID());
        break;

        case 604: // areas
        AddGossipItemFor(player, 0, "Azuremyst Isle", GOSSIP_SENDER_MAIN, 1850);
        AddGossipItemFor(player, 0, "Teldrassil", GOSSIP_SENDER_MAIN, 1851);
        AddGossipItemFor(player, 0, "Elwynn Forest", GOSSIP_SENDER_MAIN, 1852);
        AddGossipItemFor(player, 0, "Dun Morogh", GOSSIP_SENDER_MAIN, 1853);
        AddGossipItemFor(player, 0, "Durotar", GOSSIP_SENDER_MAIN, 1854);
        AddGossipItemFor(player, 0, "Mulgore", GOSSIP_SENDER_MAIN, 1855);
        AddGossipItemFor(player, 0, "Tirisfal Glades", GOSSIP_SENDER_MAIN, 1856);
        AddGossipItemFor(player, 0, "Eversong Woods", GOSSIP_SENDER_MAIN, 1857);
        AddGossipItemFor(player, 0, "Darkshore", GOSSIP_SENDER_MAIN, 1858);
        AddGossipItemFor(player, 0, "Loch Modan", GOSSIP_SENDER_MAIN, 1859);
        AddGossipItemFor(player, 0, "Redridge Mountains", GOSSIP_SENDER_MAIN, 1860);
        AddGossipItemFor(player, 0, "Barrens", GOSSIP_SENDER_MAIN, 1861);
        AddGossipItemFor(player, 0, "Stonetalon Mountains", GOSSIP_SENDER_MAIN, 1862);
        AddGossipItemFor(player, 0, "Ashenvale", GOSSIP_SENDER_MAIN, 1863);
        AddGossipItemFor(player, 0, "Wetlands", GOSSIP_SENDER_MAIN, 1864);
        AddGossipItemFor(player, 0, "Thousand Needles", GOSSIP_SENDER_MAIN, 1865);
        AddGossipItemFor(player, 0, "Hillsbrad Foothills", GOSSIP_SENDER_MAIN, 1866);
        AddGossipItemFor(player, 0, "Arathi Highlands", GOSSIP_SENDER_MAIN, 1867);
        AddGossipItemFor(player, 0, "Desolace", GOSSIP_SENDER_MAIN, 1868);
        AddGossipItemFor(player, 0, "Stranglethorn Vale", GOSSIP_SENDER_MAIN, 1869);
        AddGossipItemFor(player, 0, "Badlands", GOSSIP_SENDER_MAIN, 1870);
        AddGossipItemFor(player, 0, "Swamp of Sorrows", GOSSIP_SENDER_MAIN, 1871);
        AddGossipItemFor(player, 0, "The Hinterlands", GOSSIP_SENDER_MAIN, 1872);
        AddGossipItemFor(player, 0, "Tanaris", GOSSIP_SENDER_MAIN, 1873);
        AddGossipItemFor(player, 0, "Blasted Lands", GOSSIP_SENDER_MAIN, 1874);
        AddGossipItemFor(player, 0, "Searing Gorge", GOSSIP_SENDER_MAIN, 1875);
        AddGossipItemFor(player, 0, "Un Goro Crater", GOSSIP_SENDER_MAIN, 1876);
        AddGossipItemFor(player, 0, "Azshara", GOSSIP_SENDER_MAIN, 1877);
        AddGossipItemFor(player, 0, "Felwood", GOSSIP_SENDER_MAIN, 1878);
        AddGossipItemFor(player, 0, "Winterspring", GOSSIP_SENDER_MAIN, 1879);
        AddGossipItemFor(player, 0, "Silithus", GOSSIP_SENDER_MAIN, 1880);
        AddGossipItemFor(player, 0, "Western Plaguelands", GOSSIP_SENDER_MAIN, 1881);
        AddGossipItemFor(player, 0, "Burning Steppes", GOSSIP_SENDER_MAIN, 1882);
        AddGossipItemFor(player, 0, "Hellfire Peninsula", GOSSIP_SENDER_MAIN, 1883);
        AddGossipItemFor(player, 0, "Zangarmarsh", GOSSIP_SENDER_MAIN, 1884);
        AddGossipItemFor(player, 0, "Terokkar Forest", GOSSIP_SENDER_MAIN, 1885);
        AddGossipItemFor(player, 0, "Nagrand", GOSSIP_SENDER_MAIN, 1886);
        AddGossipItemFor(player, 0, "Blades Edge Mountain", GOSSIP_SENDER_MAIN, 1887);
        AddGossipItemFor(player, 0, "Netherstorm", GOSSIP_SENDER_MAIN, 1888);
        AddGossipItemFor(player, 0, "Shadowmoon Valley", GOSSIP_SENDER_MAIN, 1889);
        AddGossipItemFor(player, 0, "Borean Tundra", GOSSIP_SENDER_MAIN, 1890);
        AddGossipItemFor(player, 0, "Dragonblight", GOSSIP_SENDER_MAIN, 1891);
        AddGossipItemFor(player, 0, "Grizzly Hills", GOSSIP_SENDER_MAIN, 1892);
        AddGossipItemFor(player, 0, "Zul'Drak", GOSSIP_SENDER_MAIN, 1893);
        AddGossipItemFor(player, 0, "Sholazar Basin", GOSSIP_SENDER_MAIN, 1894);
        AddGossipItemFor(player, 0, "The Storm Peaks", GOSSIP_SENDER_MAIN, 1895);
        AddGossipItemFor(player, 0, "Howling Fjord", GOSSIP_SENDER_MAIN, 1896);
        AddGossipItemFor(player, 0, "Icecrown", GOSSIP_SENDER_MAIN, 1897);
        SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE,_Creature->GetGUID());
        break;

        /// tele loactions

        // RAIDS & Dungeons

        case 1900: // icc
            CloseGossipMenuFor(player);
            player->TeleportTo(571, 5873.819824f, 2110.979980f, 636.010986f, 0.0f);
            break;

        case 1901: // Naxxramas
            CloseGossipMenuFor(player);
            player->TeleportTo(571, 3665.904053f, -1267.064575f, 243.512207f, 0.0f);
            break;

        case 1902: // Ulduar
            CloseGossipMenuFor(player);
            player->TeleportTo(571, 8948.200165f, -1268.270020f, 1025.500000f, 0.0f);
            break;
        case 1903: // Nexus
            CloseGossipMenuFor(player);
            player->TeleportTo(571, 3785.800049f, 6944.919922f, 104.620003f, 0.0f);
            break;
        case 1904: // Argent tournement
            CloseGossipMenuFor(player);
            player->TeleportTo(571, 8513.266602f, 638.120728f, 547.324890f, 0.0f);
            break;
        case 1905: // Azjol-Nerub
            CloseGossipMenuFor(player);
            player->TeleportTo(571, 3707.86f, 2150.23f, 36.7568f, 0.0f);
            break;
        case 1906: // Drak' Tharon Keep
            CloseGossipMenuFor(player);
            player->TeleportTo(571, 4774.6f, -2032.92f, 229.145f, 0.0f);
            break;
        case 1907: // Gundrak
            CloseGossipMenuFor(player);
            player->TeleportTo(571, 6910.8f, -4603.23f, 450.61f, 0.0f);
            break;
        case 1908: // Utgarde Keep
            CloseGossipMenuFor(player);
            player->TeleportTo(571, 1219.72f, -4865.28f, 41.2479f, 0.0f);
            break;
        case 1909: // Utgarde Pinnacle
            CloseGossipMenuFor(player);
            player->TeleportTo(571, 1259.33f, -4852.02f, 215.763f, 0.0f);
            break;
        case 1910: // Vault of Archavon
            CloseGossipMenuFor(player);
            player->TeleportTo(571, 5453.72f, 2840.79f, 421.277f, 0.0f);
            break;
        case 1911: // Violet Hold
            CloseGossipMenuFor(player);
            player->TeleportTo(571, 5689.03f, 508.278f, 652.763f, 0.0f);
            break;

/////// cities

        case 1800: // Stormwind
        CloseGossipMenuFor(player);
        player->TeleportTo(0, -8960.14f, 516.266f, 96.3568f, 0.0f); // Teleport(location)
        break;

        case 1801: // Ironforge
        CloseGossipMenuFor(player);
        player->TeleportTo(0, -4924.07f, -951.95f, 501.55f, 5.40f);
        break;

        case 1802: // Darnassus
        CloseGossipMenuFor(player);
        player->TeleportTo(1, 9947.52f, 2482.73f, 1316.21f, 0.0f);
        break;

        case 1803: // Exodar
        CloseGossipMenuFor(player);
        player->TeleportTo(530, -3954.20f, -11656.54f, -138.69f, 0.0f);
        break;

        case 1804: // Shattrath
        CloseGossipMenuFor(player);
        player->TeleportTo(530, -1850.209961f, 5435.821777f, -10.961435f, 3.403913f);
        break;

        case 1805: // Dalaran
        CloseGossipMenuFor(player);
        player->TeleportTo(571, 5819.08f, 643.99f, 647.80f, 3.32f);
        break;

        case 1806: // Gurubashi Arena
        CloseGossipMenuFor(player);

        player->TeleportTo(0,  -13277.4f, 127.372f, 26.1418f, 1.0f);
        break;

        case 1807: // Orgrimmar
         CloseGossipMenuFor(player);
        player->TeleportTo(1, 1552.5f, -4420.66f, 8.94802f, 0.0f);
        break;

        case 1808: // Undercity
        CloseGossipMenuFor(player);
        player->TeleportTo(0, 1819.71f, 238.79f, 60.5321f, 0.0f);

        break;

        case 1809: // Silvermoon
        CloseGossipMenuFor(player);
        player->TeleportTo(530, 9338.74f, -7277.27f, 13.7895f, 0.0f);
        break;

        case 1810: // Thunder Bluff
        CloseGossipMenuFor(player);
        player->TeleportTo(1, -1290.0f, 147.033997f, 129.682007f, 4.919000f);
        break;

        case 5001: // Horde Mall
        CloseGossipMenuFor(player);
        player->TeleportTo(HMM, HMX, HMY, HMZ, 0.0f);
        break;

        case 5000: // Alliance Mall
        CloseGossipMenuFor(player);
        player->TeleportTo(AMM, AMX, AMY, AMZ, 0.0f);
        break;

// Leveling Roads
        case 9999:    // horde level road
        CloseGossipMenuFor(player);
        player->TeleportTo(HLM, HLX, HLY, HLZ, 0.0f);
        break;

        case 9998:    //alliance level road
        CloseGossipMenuFor(player);
        player->TeleportTo(ALM, ALX, ALY, ALZ, 0.0f);
        break;
// Zones
        case 1850:  // Azuremyst Isle
        CloseGossipMenuFor(player);
        player->TeleportTo(530, -4216.870117f, -12336.900391f, 4.340638f, 0.0f);
        break;
        case 1851:  // Teldrassil
        CloseGossipMenuFor(player);
        player->TeleportTo(1, 10111.299805f, 1557.729980f, 1324.329956f, 0.0f);
        break;
        case 1852:  // Elwynn Forest
        CloseGossipMenuFor(player);
        player->TeleportTo(0, -9617.059570f, -288.949005f, 57.305149f, 0.0f);
        break;
        case 1853:  // Dun Morogh
        CloseGossipMenuFor(player);
        player->TeleportTo(0, -5451.549805f, -656.992004f, 392.674988f, 0.0f);
        break;
        case 1854:  // Durotar
        CloseGossipMenuFor(player);
        player->TeleportTo(1, 1007.780029f, -446.220215f, 11.202200f, 0.0f);
        break;
        case 1855:  // Mulgore
        CloseGossipMenuFor(player);
        player->TeleportTo(1, -2192.620117f, -736.317017f, -13.327400f, 0.0f);
        break;
        case 1856:  // Tirisfal Glades
        CloseGossipMenuFor(player);
        player->TeleportTo(0, 2036.020020f, 161.330994f, 33.867401f, 0.0f);
        break;
        case 1857:  // Eversong Woods
        CloseGossipMenuFor(player);
        player->TeleportTo(530, 9079.919922f, -7193.229980f, 55.601299f, 0.0f);
        break;
        case 1858:  // Darkshore
        CloseGossipMenuFor(player);
        player->TeleportTo(1, 5756.250000f, 298.505005f, 20.604900f, 0.0f);
        break;
        case 1859:  // Loch Modan
        CloseGossipMenuFor(player);
        player->TeleportTo(0, -5202.939941f, -2855.179932f, 335.953827f, 0.0f);
        break;
        case 1860:  // Redridge Mountains
        CloseGossipMenuFor(player);
        player->TeleportTo(0, -9551.809570f, -2204.729980f, 93.473000f, 0.0f);
        break;
        case 1861:  // The Barrens
        CloseGossipMenuFor(player);
        player->TeleportTo(1, 884.539978f, -3548.449951f, 91.853165f, 0.0f);
        break;
        case 1862:  // Stonetalon Mountains
        CloseGossipMenuFor(player);
        player->TeleportTo(1, 1570.920044f, 1031.520020f, 137.959000f, 0.0f);
        break;
        case 1863:  // Ashenvale
        CloseGossipMenuFor(player);
        player->TeleportTo(1, 1928.339966f, -2165.949951f, 93.789597f, 0.0f);
        break;
        case 1864:  // Wetlands
        CloseGossipMenuFor(player);
        player->TeleportTo(0, -3242.810059f, -2469.040039f, 15.922600f, 0.0f);
        break;
        case 1865:  // Thousand Needles
        CloseGossipMenuFor(player);
        player->TeleportTo(1, -4969.020020f, -1726.890015f, -62.126911f, 0.0f);
        break;
        case 1866:  // Hillsbrad Foothills
        CloseGossipMenuFor(player);
        player->TeleportTo(0, -436.657013f, -581.254028f, 53.594398f, 0.0f);
        break;
        case 1867:  // Arathi Highlands
        CloseGossipMenuFor(player);
        player->TeleportTo(0, -1508.510010f, -2732.060059f, 32.498600f, 0.0f);
        break;
        case 1868:  // Desolace
        CloseGossipMenuFor(player);
        player->TeleportTo(1, -606.395020f, 2211.750000f, 92.981796f, 0.0f);
        break;
        case 1869:  // Stranglethorn Vale
        CloseGossipMenuFor(player);
        player->TeleportTo(0, -12644.299805f, -377.411011f, 10.102062f, 0.0f);
        break;
        case 1870:  // Badlands
        CloseGossipMenuFor(player);
        player->TeleportTo(0, -6779.200195f, -3423.639893f, 241.667007f, 0.0f);
        break;
        case 1871:  // Spawm of Sorrows
        CloseGossipMenuFor(player);
        player->TeleportTo(0, -10345.400391f, -2773.419922f, 21.990000f, 0.0f);
        break;
        case 1872:  // The Hinterlands
        CloseGossipMenuFor(player);
        player->TeleportTo(0, 119.387001f, -3190.370117f, 117.330994f, 0.0f);
        break;
        case 1873:  // Tanaris
        CloseGossipMenuFor(player);
        player->TeleportTo(1, -7931.200195f, -3414.280029f, 80.736496f, 0.0f);
        break;
        case 1874:  // Blasted Lands
        CloseGossipMenuFor(player);
        player->TeleportTo(0, -11182.500000f, -3016.669922f, 7.422350f, 0.0f);
        break;
        case 1875:  // Searing Gorge
        CloseGossipMenuFor(player);
        player->TeleportTo(0, -7012.470215f, -1065.130005f, 241.785995f, 0.0f);
        break;
        case 1876:  // Un Goro Crater
        CloseGossipMenuFor(player);
        player->TeleportTo(1, -7943.220215f, -2119.090088f, -218.344589f, 0.0f);
        break;
        case 1877:  // Azshara
        CloseGossipMenuFor(player);
        player->TeleportTo(1, 3341.360107f, -4603.790039f, 92.502701f, 0.0f);
        break;
        case 1878:  // Felwood
        CloseGossipMenuFor(player);
        player->TeleportTo(1, 4102.250000f, -1006.789978f, 272.717010f, 0.0f);
        break;
        case 1879:  // Winterspring
        CloseGossipMenuFor(player);
        player->TeleportTo(1, 6759.180176f, -4419.629883f, 763.213989f, 0.0f);
        break;
        case 1880:  // Silithus
        CloseGossipMenuFor(player);
        player->TeleportTo(1, -7426.870117f, 1005.309998f, 1.133590f, 0.0f);
        break;
        case 1881:  // Western Plaguelands
        CloseGossipMenuFor(player);
        player->TeleportTo(0, 1728.650024f, -1602.250000f, 63.428963f, 0.0f);
        break;
        case 1882:  // Burning Steppes
        CloseGossipMenuFor(player);
        player->TeleportTo(0, -8118.540039f, -1633.829956f, 132.996002f, 0.0f);
        break;
        case 1883:  // Hellfire Peninsula
        CloseGossipMenuFor(player);
        player->TeleportTo(530, -211.237000f, 4278.540039f, 86.567802f, 0.0f);
        break;
        case 1884:  // Zangarmarsh
        CloseGossipMenuFor(player);
        player->TeleportTo(530, -54.862099f, 5813.439941f, 20.605900f, 0.0f);
        break;
        case 1885:  // Terokkar Forest
        CloseGossipMenuFor(player);
        player->TeleportTo(530, -2000.469971f, 4451.540039f, 8.369170f, 0.0f);
        break;
        case 1886:  // Nagrand
        CloseGossipMenuFor(player);
        player->TeleportTo(530, -1145.949951f, 8182.350098f, 3.602490f, 0.0f);
        break;
        case 1887:  // Blades Edge Mountain
        CloseGossipMenuFor(player);
        player->TeleportTo(530, 3037.669922f, 5962.859863f, 130.774002f, 0.0f);
        break;
        case 1888:  // Netherstorm
        CloseGossipMenuFor(player);
        player->TeleportTo(530, 3830.229980f, 3426.500000f, 88.614502f, 0.0f);
        break;
        case 1889:  // Shadowmoon Valley
        CloseGossipMenuFor(player);
        player->TeleportTo(530, -3077.271973f, 2878.689209f, 82.129242f, 0.0f);
        break;
        case 1890:  // Borean Tundra
        CloseGossipMenuFor(player);
        player->TeleportTo(571, 3256.570068f, 5278.229980f, 40.804588f, 0.0f);
        break;
        case 1891:  // Dragonblight
        CloseGossipMenuFor(player);
        player->TeleportTo(571, 4103.359863f, 264.477997f, 50.501900f, 0.0f);
        break;
        case 1892:  // Grizzly Hills
        CloseGossipMenuFor(player);
        player->TeleportTo(571, 4391.729980f, -3587.919922f, 238.531006f, 0.0f);
        break;
        case 1893:  // Zul' Drak
        CloseGossipMenuFor(player);
        player->TeleportTo(571, 5560.229980f, -3211.659912f, 371.709015f, 0.0f);
        break;
        case 1894:  // Sholazar Basin
        CloseGossipMenuFor(player);
        player->TeleportTo(571, 5323.000000f, 4942.000000f, -133.558670f, 0.0f);
        break;
        case 1895:  // The Storm Peaks
        CloseGossipMenuFor(player);
        player->TeleportTo(571, 7527.140137f, -1260.890015f, 919.049011f, 0.0f);
        break;
        case 1896:  // Howling Fjord
        CloseGossipMenuFor(player);
        player->TeleportTo(571, 1902.150024f, -4883.910156f, 161.363007f, 0.0f);
        break;
        case 1897:  // Icecrown
        CloseGossipMenuFor(player);
        player->TeleportTo(571, 7253.640137f, 1644.780029f, 433.679993f, 0.0f);
        break;


        /// -- Tele part stop -- ///

    /// -- Dungeons, Raids -- ///


        /// -- BG Control Part Start -- ///
            AddGossipItemFor(player, 0, "WSG 100%", GOSSIP_SENDER_MAIN, 1400);
        AddGossipItemFor(player, 0, "EOTS 100%", GOSSIP_SENDER_MAIN, 1401);
        AddGossipItemFor(player, 0, "AB 100%", GOSSIP_SENDER_MAIN, 1402);
        AddGossipItemFor(player, 0, "SOTA 100%", GOSSIP_SENDER_MAIN, 1403);
        AddGossipItemFor(player, 0, "AV 100%", GOSSIP_SENDER_MAIN, 1404); // LOL!

        case 1400: // WSG 100%
        /* Comment: IDS:
        SOTA - 9
        AV - 1
        WSG - 2
        AB - 3
        EOTS - 7*/
        CloseGossipMenuFor(player);
        WorldDatabase.PQuery("UPDATE `battleground_template` SET `Weight`=0 WHERE `id` IN(1, 3, 7, 9)");
        WorldDatabase.PQuery("UPDATE `battleground_template` SET `Weight`=10 WHERE `id`=2");
        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Done", GOSSIP_SENDER_MAIN, 12345);
        break;

        case 1401: // EOTS 100%
        CloseGossipMenuFor(player);
        WorldDatabase.PQuery("UPDATE `battleground_template` SET `Weight`=0 WHERE `id` IN(1, 3, 2, 9)");
        WorldDatabase.PQuery("UPDATE `battleground_template` SET `Weight`=10 WHERE `id`=7");
        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Done", GOSSIP_SENDER_MAIN, 12345);
        break;

        case 1402: // AB 100%
        CloseGossipMenuFor(player);
        WorldDatabase.PQuery("UPDATE `battleground_template` SET `Weight`=0 WHERE `id` IN(1, 2, 7, 9)");
        WorldDatabase.PQuery("UPDATE `battleground_template` SET `Weight`=10 WHERE `id`=3");
        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Done", GOSSIP_SENDER_MAIN, 12345);
        break;

        case 1403: // Sota 100%
        CloseGossipMenuFor(player);
        WorldDatabase.PQuery("UPDATE `battleground_template` SET `Weight`=0 WHERE `id` IN(1, 3, 7, 2)");
        WorldDatabase.PQuery("UPDATE `battleground_template` SET `Weight`=10 WHERE `id`=9");
        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Done", GOSSIP_SENDER_MAIN, 12345);
        break;

        case 1404: // AV 100%
        CloseGossipMenuFor(player);
        WorldDatabase.PQuery("UPDATE `battleground_template` SET `Weight`=0 WHERE `id` IN(2, 3, 7, 9)");
        WorldDatabase.PQuery("UPDATE `battleground_template` SET `Weight`=10 WHERE `id`=1");
        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Done", GOSSIP_SENDER_MAIN, 12345);
        break;

        /// -- BG Modify Part End -- ///

        /* Break */





        /// -- Token Part Start -- ///

        /*
            case 107: // Token -> BUY
        AddGossipItemFor(player, 0, tokenbuy, GOSSIP_SENDER_MAIN, 1200);
        break;

        case 108: // Token ->Change
        AddGossipItemFor(player, 0, tokenchange, GOSSIP_SENDER_MAIN, 1300);
        break;
        */

        case 1201: // Token change
        if(player->HasItemCount(token1, 1, false))
        {
        player->ItemRemovedQuestCheck(token1, 1);
        player->AddItem(token2, 1);
        } else {
        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "You don't have got enough token.", GOSSIP_SENDER_MAIN, 12345);
        break;
        }

        case 1200:
        AddGossipItemFor(player, 0, tokenbuy, GOSSIP_SENDER_MAIN, 2000, "Are you sure you want to buy a token?", -10000, 0);
        break;
        case 2000:
        player->AddItem(vasarolhatotoken, 1);
        break;

        ///-- Token Part End --///

        ///-- Trainers Part Start --///
        /*
        AddGossipItemFor(player, 1, "Prof Trainer", GOSSIP_SENDER_MAIN, 800);
        AddGossipItemFor(player, 1, "Class Trainer", GOSSIP_SENDER_MAIN, 801);
        AddGossipItemFor(player, 1, "Weapon Trainer", GOSSIP_SENDER_MAIN, 802);
        AddGossipItemFor(player, 1, "Mount Trainer", GOSSIP_SENDER_MAIN, 803);
        */

        case 803: // Mount Trainer
        {
        CloseGossipMenuFor(player);
        player->LearnSpell(33388, false);
        player->LearnSpell(33391, false);
        player->LearnSpell(34090, false);
        player->LearnSpell(34091, false);
        player->LearnSpell(54197, false);
        }

        case 800: // profs
        // SPGM
        AddGossipItemFor(player, 3, "Alchemy"                     , GOSSIP_SENDER_MAIN, 2100);
        AddGossipItemFor(player, 3, "Blacksmithing"           , GOSSIP_SENDER_MAIN, 2101);
        AddGossipItemFor(player, 3, "Enchanter"        , GOSSIP_SENDER_MAIN, 2102);
        AddGossipItemFor(player, 3, "Engineering"              , GOSSIP_SENDER_MAIN, 2103);
        AddGossipItemFor(player, 3, "Herbalism"            , GOSSIP_SENDER_MAIN, 2104);
        AddGossipItemFor(player, 3, "Inscription"        , GOSSIP_SENDER_MAIN, 2105);
        AddGossipItemFor(player, 3, "Jewelcrafting"           , GOSSIP_SENDER_MAIN, 2106);
        AddGossipItemFor(player, 3, "Leatherworking"           , GOSSIP_SENDER_MAIN, 2107);
        AddGossipItemFor(player, 3, "Mining"                , GOSSIP_SENDER_MAIN, 2108);
        AddGossipItemFor(player, 3, "Skinning"        , GOSSIP_SENDER_MAIN, 2109);
        AddGossipItemFor(player, 3, "Tailoring"                  , GOSSIP_SENDER_MAIN, 2110);
        AddGossipItemFor(player, 3, "Cooking"              , GOSSIP_SENDER_MAIN, 2111);
        AddGossipItemFor(player, 3, "First Aid"            , GOSSIP_SENDER_MAIN, 2112);
        AddGossipItemFor(player, 3, "Fishing"              , GOSSIP_SENDER_MAIN, 2113);
        SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE,_Creature->GetGUID());
        break;
        case 801: // Class Trainers

        AddGossipItemFor(player, 3, "Death Knight"          , GOSSIP_SENDER_MAIN, 2200);
        AddGossipItemFor(player, 3, "Druid"               , GOSSIP_SENDER_MAIN, 2201);
        AddGossipItemFor(player, 3, "Hunter"            , GOSSIP_SENDER_MAIN, 2202);
        AddGossipItemFor(player, 3, "Mage"            , GOSSIP_SENDER_MAIN, 2203);
        AddGossipItemFor(player, 3, "Paladin"             , GOSSIP_SENDER_MAIN, 2204);
        AddGossipItemFor(player, 3, "Priest"                , GOSSIP_SENDER_MAIN, 2205);
        AddGossipItemFor(player, 3, "Rogue"                       , GOSSIP_SENDER_MAIN, 2206);
        AddGossipItemFor(player, 3, "Shaman"               , GOSSIP_SENDER_MAIN, 2207);
        AddGossipItemFor(player, 3, "Warlock"        , GOSSIP_SENDER_MAIN, 2208);
        AddGossipItemFor(player, 3, "Warrior"                 , GOSSIP_SENDER_MAIN, 2209);
        SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE,_Creature->GetGUID());
        break;

        case 2200:
        CloseGossipMenuFor(player);
        player->SummonCreature(dk,player->GetPositionX() ,player->GetPositionY(), player->GetPositionZ(), 0,TEMPSUMMON_TIMED_DESPAWN,120000);
        break;

        case 2201:
        CloseGossipMenuFor(player);
        player->SummonCreature(dudu,player->GetPositionX() ,player->GetPositionY(), player->GetPositionZ(), 0,TEMPSUMMON_TIMED_DESPAWN,120000);
        break;

        case 2202:
        CloseGossipMenuFor(player);
        player->SummonCreature(hunta,player->GetPositionX() ,player->GetPositionY(), player->GetPositionZ(), 0,TEMPSUMMON_TIMED_DESPAWN,120000);
        break;

           case 2203:
        CloseGossipMenuFor(player);
        player->SummonCreature(mage,player->GetPositionX() ,player->GetPositionY(), player->GetPositionZ(), 0,TEMPSUMMON_TIMED_DESPAWN,120000);
        break;

        case 2204:
        CloseGossipMenuFor(player);
        player->SummonCreature(pala,player->GetPositionX() ,player->GetPositionY(), player->GetPositionZ(), 0,TEMPSUMMON_TIMED_DESPAWN,120000);
        break;

           case 2205:
        CloseGossipMenuFor(player);
        player->SummonCreature(priest,player->GetPositionX() ,player->GetPositionY(), player->GetPositionZ(), 0,TEMPSUMMON_TIMED_DESPAWN,120000);
        break;

           case 2206:
        CloseGossipMenuFor(player);
        player->SummonCreature(rogue,player->GetPositionX() ,player->GetPositionY(), player->GetPositionZ(), 0,TEMPSUMMON_TIMED_DESPAWN,120000);
        break;

        case 2207:
        CloseGossipMenuFor(player);
        player->SummonCreature(sami,player->GetPositionX() ,player->GetPositionY(), player->GetPositionZ(), 0,TEMPSUMMON_TIMED_DESPAWN,120000);
        break;

           case 2208:
        CloseGossipMenuFor(player);
        player->SummonCreature(lock,player->GetPositionX() ,player->GetPositionY(), player->GetPositionZ(), 0,TEMPSUMMON_TIMED_DESPAWN,120000);
        break;

           case 2209:
        CloseGossipMenuFor(player);
        player->SummonCreature(wari,player->GetPositionX() ,player->GetPositionY(), player->GetPositionZ(), 0,TEMPSUMMON_TIMED_DESPAWN,120000);
        break;

        //Sickness,Reset Talent Start//
        case 121: // Reset Talent Pont
        CloseGossipMenuFor(player);
        player->SendTalentWipeConfirm(_Creature->GetGUID());
        break;

        case 120: //Sickness leszed�se
        if(!player->HasAura(SPELL_ID_PASSIVE_RESURRECTION_SICKNESS))
        {
            _Creature->Whisper(nosickness, LANG_UNIVERSAL, player);
        }
        else
        {
        _Creature->CastSpell(player,38588,false); // Flash Heal
        player->RemoveAurasDueToSpell(SPELL_ID_PASSIVE_RESURRECTION_SICKNESS);
        }
        CloseGossipMenuFor(player);
        break;
        //Sickness,Reset Talent End//
        ////// Prof trainers

        case 2100: // Alchemy
        CloseGossipMenuFor(player);
        player->SummonCreature(33630,player->GetPositionX() ,player->GetPositionY(), player->GetPositionZ(), 0,TEMPSUMMON_TIMED_DESPAWN,120000);
        player->SummonCreature(28703,player->GetPositionX() ,player->GetPositionY(), player->GetPositionZ(), 0,TEMPSUMMON_TIMED_DESPAWN,120000);
        break;

        case 2101: // Blacksmithing
        CloseGossipMenuFor(player);
        player->SummonCreature(28694,player->GetPositionX() ,player->GetPositionY(), player->GetPositionZ(), 0,TEMPSUMMON_TIMED_DESPAWN,120000);
        break;

case 2102: // Enchanting
    CloseGossipMenuFor(player);
    player->SummonCreature(28693,player->GetPositionX() ,player->GetPositionY(), player->GetPositionZ(), 0,TEMPSUMMON_TIMED_DESPAWN,120000);
    player->SummonCreature(33633,player->GetPositionX() ,player->GetPositionY(), player->GetPositionZ(), 0,TEMPSUMMON_TIMED_DESPAWN,120000);
break;

        case 2103: // Engineering
   CloseGossipMenuFor(player);
    player->SummonCreature(28697,player->GetPositionX() ,player->GetPositionY(), player->GetPositionZ(), 0,TEMPSUMMON_TIMED_DESPAWN,120000);
break;

case 2104: // Herbalism
    CloseGossipMenuFor(player);
    player->SummonCreature(28704,player->GetPositionX() ,player->GetPositionY(), player->GetPositionZ(), 0,TEMPSUMMON_TIMED_DESPAWN,120000);
break;
case 2105: // Inscription
 CloseGossipMenuFor(player);
    player->SummonCreature(28702,player->GetPositionX() ,player->GetPositionY(), player->GetPositionZ(), 0,TEMPSUMMON_TIMED_DESPAWN,120000);
break;

case 2106: // Jewelcrafting
    CloseGossipMenuFor(player);
    player->SummonCreature(28701,player->GetPositionX() ,player->GetPositionY(), player->GetPositionZ(), 0,TEMPSUMMON_TIMED_DESPAWN,120000);
break;

case 2107: // Leatherworking
    CloseGossipMenuFor(player);
    player->SummonCreature(28700,player->GetPositionX() ,player->GetPositionY(), player->GetPositionZ(), 0,TEMPSUMMON_TIMED_DESPAWN,120000);
break;

case 2108: // Mining
    CloseGossipMenuFor(player);    player->SummonCreature(28698,player->GetPositionX() ,player->GetPositionY(), player->GetPositionZ(), 0,TEMPSUMMON_TIMED_DESPAWN,120000);
break;

case 2109: // Skinning
    CloseGossipMenuFor(player);
    player->SummonCreature(28696,player->GetPositionX() ,player->GetPositionY(), player->GetPositionZ(), 0,TEMPSUMMON_TIMED_DESPAWN,120000);
break;

case 2110: // Tailoring
    CloseGossipMenuFor(player);
    player->SummonCreature(28699,player->GetPositionX() ,player->GetPositionY(), player->GetPositionZ(), 0,TEMPSUMMON_TIMED_DESPAWN,120000);
break;

case 2111: // Cooking
   CloseGossipMenuFor(player);
    player->SummonCreature(28705,player->GetPositionX() ,player->GetPositionY(), player->GetPositionZ(), 0,TEMPSUMMON_TIMED_DESPAWN,120000);
break;

case 2112: // First Aid
    CloseGossipMenuFor(player);
    player->SummonCreature(28706,player->GetPositionX() ,player->GetPositionY(), player->GetPositionZ(), 0,TEMPSUMMON_TIMED_DESPAWN,120000);
break;

        case 2113: // Fishing
    CloseGossipMenuFor(player);
    player->SummonCreature(28742,player->GetPositionX() ,player->GetPositionY(), player->GetPositionZ(), 0,TEMPSUMMON_TIMED_DESPAWN,120000);
break;
}
//return true;
    }

static bool OnGossipSelect(Player* player, Creature* _Creature, uint32 sender, uint32 action)
{
    // Main menu
    player->PlayerTalkClass->ClearMenus();
    if (sender == GOSSIP_SENDER_MAIN)
    SendDefaultMenu(player, _Creature, action);

return true;
}

static bool OnGossipSelectCode(Player* player, Creature* m_creature, uint32 uiSender, uint32 uiAction, char const* code)
    {
        player->PlayerTalkClass->ClearMenus();

        return true;
    }

struct MyAI : public ScriptedAI
    {
        MyAI(Creature* m_creature) : ScriptedAI(m_creature) { }
        bool GossipHello(Player* player) override
        {
            return OnGossipHello(player, me);
        }
        bool GossipSelect(Player* player, uint32 menuId, uint32 gossipListId) override
        {
            uint32 sender = player->PlayerTalkClass->GetGossipOptionSender(gossipListId);
            uint32 action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
            return OnGossipSelect(player, me, sender, action);
        }
        bool GossipSelectCode(Player* player, uint32 menuId, uint32 gossipListId, char const* code) override
        {
            uint32 sender = player->PlayerTalkClass->GetGossipOptionSender(gossipListId);
            uint32 action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
            return OnGossipSelectCode(player, me, sender, action, code);
        }
    };


CreatureAI* GetAI(Creature* m_creature) const override
    {
        return new MyAI(m_creature);
    }
};

void AddSC_npc_all()
{
    new npc_all();
}
