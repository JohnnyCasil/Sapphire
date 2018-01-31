#include "../ScriptObject.h"

class ManSea001 : public EventScript
{
private:
   // Steps in this quest ( 0 is before accepting,
   // 1 is first, 255 means ready for turning it in
   static constexpr auto SEQ_0 = 0;
   static constexpr auto SEQ_1 = 1;
   static constexpr auto SEQ_FINISH = 255;

   static constexpr auto ACTOR0 = 1001028;
   static constexpr auto ACTOR1 = 1002732;
   static constexpr auto ACTOR2 = 1002697;
   static constexpr auto CUT_EVENT = 202;
   static constexpr auto EOBJECT0 = 2001679;
   static constexpr auto EOBJECT1 = 2001680;
   static constexpr auto EVENT_ACTION_SEARCH = 1;
   static constexpr auto LOC_ACTOR0 = 1002732;
   static constexpr auto LOC_POS_ACTOR0 = 4107186;
   static constexpr auto OPENING_EVENT_HANDLER = 1245185;
   static constexpr auto POPRANGE0 = 4127803;
   static constexpr auto TERRITORYTYPE0 = 181;

   void Scene00000( Entity::Player& player )
   {
      auto callback = [ this ]( Entity::Player& player, uint32_t eventId, uint16_t param1, uint16_t param2, uint16_t param3 )
      {
         if( param2 == 1 )
         {
            player.setOpeningSequence( 2 );
            Scene00001( player );
         }
      };

      player.eventPlay( getId(), 0, HIDE_HOTBAR, 0, 0, callback );
   }

   void Scene00001( Entity::Player& player )
   {
      auto callback = [ this ]( Entity::Player& player, uint32_t eventId, uint16_t param1, uint16_t param2, uint16_t param3 )
      {
         Scene00002( player );
      };

      player.eventPlay( getId(), 1, 0xF8482EFB, 0, 0, callback );
   }

   void Scene00002( Entity::Player& player )
   {
      auto callback = [ this ]( Entity::Player& player, uint32_t eventId, uint16_t param1, uint16_t param2, uint16_t param3 )
      {
         Scene00003( player );
      };

      player.eventPlay( getId(), 2, NONE, 0, 0, callback );
   }

   void Scene00003( Entity::Player& player )
   {
      auto callback = [ this ]( Entity::Player& player, uint32_t eventId, uint16_t param1, uint16_t param2, uint16_t param3 )
      {
         player.updateQuest( getId(), 1 );

         player.eventPlay( OPENING_EVENT_HANDLER, 0x1E, HIDE_HOTBAR | NO_DEFAULT_CAMERA, 1, 0 );
      };

      player.eventPlay( getId(), 3, NONE, 0, 0, callback );
   }

   void Scene00004( Entity::Player& player )
   {
      player.eventPlay( getId(), 4, NONE, 0, 0 );
   }

   void Scene00005( Entity::Player& player )
   {
      auto callback = [ this ]( Entity::Player& player, uint32_t eventId, uint16_t param1, uint16_t param2, uint16_t param3 )
      {
         Scene00006( player );
      };

      player.eventPlay( getId(), 5, HIDE_HOTBAR, 0, 0, callback );
   }

   void Scene00006( Entity::Player& player )
   {
      auto callback = [ this ]( Entity::Player& player, uint32_t eventId, uint16_t param1, uint16_t param2, uint16_t param3 )
      {
         player.updateQuest( getId(), SEQ_FINISH );
         player.prepareZoning( player.getZoneId(), true, 1, 0 );
         player.changePosition( 9, 40, 14, 2 );
      };

      player.eventPlay( getId(), 6, INVIS_OTHER_PC, 0, 0, callback );
   }

   void Scene00007( Entity::Player& player )
   {
      player.eventPlay( getId(), 7, NONE, 0, 0 );
   }

   void Scene00008( Entity::Player& player )
   {
      player.eventPlay( getId(), 8, NONE, 0, 0 );
   }

   void Scene00009( Entity::Player& player )
   {
      player.eventPlay( getId(), 9, NONE, 0, 0 );
   }

   void Scene00010( Entity::Player& player )
   {
      player.eventPlay( getId(), 10, NONE, 0, 0 );
   }

   void Scene00011( Entity::Player& player )
   {
      auto callback = [ this ]( Entity::Player& player, uint32_t eventId, uint16_t param1, uint16_t param2, uint16_t param3 )
      {
         Scene00012( player );
      };

      player.eventPlay( getId(), 11, 0x2c02, 0, 0, callback );
   }

   void Scene00012( Entity::Player& player )
   {
      auto callback = [ this ]( Entity::Player& player, uint32_t eventId, uint16_t param1, uint16_t param2, uint16_t param3 )
      {
         if( param2 == 1 ) // finish quest
         {
            if( player.giveQuestRewards( getId(), 0 ) )
               player.finishQuest( getId() );
         }
      };

      player.eventPlay( getId(), 12, INVIS_OTHER_PC, 0, 0, callback );
   }

   void Scene00013( Entity::Player& player )
   {
      player.eventPlay( getId(), 13, NONE, 0, 0 );
   }

public:
   ManSea001() : EventScript( 65643 ) {}

   void onTalk( uint32_t eventId, Entity::Player& player, uint64_t actorId ) override
   {
      auto actor = Event::mapEventActorToRealActor( static_cast< uint32_t >( actorId ) );

      if( actor == ACTOR0 )
         Scene00000( player );
      else if( actor == ACTOR1 )
         Scene00005( player );
      else if( actor == ACTOR2 )
         Scene00011( player );
   }
};