#ifndef GAME_BASE_INVIRONMENT_H
#define GAME_BASE_INVIRONMENT_H

namespace MWGui
{
    class WindowManager;
}

namespace MWMechanics
{
    class MechanicsManager;
}

namespace MWInput
{
    struct MWInputManager;
}

namespace MWBase
{
    class World;
    class ScriptManager;
    class DialogueManager;
    class Journal;
    class SoundManager;

    /// \brief Central hub for mw-subsystems
    ///
    /// This class allows each mw-subsystem to access any others subsystem's top-level manager class.
    ///
    /// \attention Environment takes ownership of the manager class instances it is handed over in
    /// the set* functions.
    class Environment
    {
            static Environment *sThis;

            World *mWorld;
            SoundManager *mSoundManager;
            ScriptManager *mScriptManager;
            MWGui::WindowManager *mWindowManager;
            MWMechanics::MechanicsManager *mMechanicsManager;
            DialogueManager *mDialogueManager;
            Journal *mJournal;
            MWInput::MWInputManager *mInputManager;
            float mFrameDuration;

            Environment (const Environment&);
            ///< not implemented

            Environment& operator= (const Environment&);
            ///< not implemented

        public:

            Environment();

            ~Environment();

            void setWorld (World *world);

            void setSoundManager (SoundManager *soundManager);

            void setScriptManager (MWBase::ScriptManager *scriptManager);

            void setWindowManager (MWGui::WindowManager *windowManager);

            void setMechanicsManager (MWMechanics::MechanicsManager *mechanicsManager);

            void setDialogueManager (DialogueManager *dialogueManager);

            void setJournal (Journal *journal);

            void setInputManager (MWInput::MWInputManager *inputManager);

            void setFrameDuration (float duration);
            ///< Set length of current frame in seconds.

            World *getWorld() const;

            SoundManager *getSoundManager() const;

            MWBase::ScriptManager *getScriptManager() const;

            MWGui::WindowManager *getWindowManager() const;

            MWMechanics::MechanicsManager *getMechanicsManager() const;

            DialogueManager *getDialogueManager() const;

            Journal *getJournal() const;

            MWInput::MWInputManager *getInputManager() const;

            float getFrameDuration() const;

            void cleanup();
            ///< Delete all mw*-subsystems.

            static const Environment& get();
            ///< Return instance of this class.
    };
}

#endif
