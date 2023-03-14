#include "LSinger.h"

namespace fnf
{
	class Animator;
	class Boyfriend : public Singer
	{
	public:
		Boyfriend();
		~Boyfriend();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

	private:
		void Move();
		void BFWriteFile();
	private:
		Animator* mAnimator;
		
	};
}
