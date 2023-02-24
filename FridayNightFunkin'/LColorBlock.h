
#include "LGameObject.h"
#include "LImage.h"
namespace fnf
{
	class ColorBlock : public GameObject
	{
	public:

		ColorBlock(COLORREF color);
		ColorBlock(COLORREF color, UINT width, UINT height);
		~ColorBlock();

		virtual void Initialize()override;
		virtual void Update()override;
		virtual void Render(HDC hdc)override;
		virtual void Release()override;

		void SetColor(COLORREF color);
	private:
		COLORREF mRGB;
		UINT mWidth;
		UINT mHeight;
		HBRUSH mBrush;
	};
}