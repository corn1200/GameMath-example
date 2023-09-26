
#include "Precompiled.h"
#include "SoftRenderer.h"
#include <random>
using namespace CK::DD;

// 격자를 그리는 함수
void SoftRenderer::DrawGizmo2D()
{
	auto& r = GetRenderer();
	const auto& g = Get2DGameEngine();

	// 그리드 색상
	LinearColor gridColor(LinearColor(0.8f, 0.8f, 0.8f, 0.3f));

	// 뷰의 영역 계산
	Vector2 viewPos = g.GetMainCamera().GetTransform().GetPosition();
	Vector2 extent = Vector2(_ScreenSize.X * 0.5f, _ScreenSize.Y * 0.5f);

	// 좌측 하단에서부터 격자 그리기
	int xGridCount = _ScreenSize.X / _Grid2DUnit;
	int yGridCount = _ScreenSize.Y / _Grid2DUnit;

	// 그리드가 시작되는 좌하단 좌표 값 계산
	Vector2 minPos = viewPos - extent;
	Vector2 minGridPos = Vector2(ceilf(minPos.X / (float)_Grid2DUnit), ceilf(minPos.Y / (float)_Grid2DUnit)) * (float)_Grid2DUnit;
	ScreenPoint gridBottomLeft = ScreenPoint::ToScreenCoordinate(_ScreenSize, minGridPos - viewPos);

	for (int ix = 0; ix < xGridCount; ++ix)
	{
		r.DrawFullVerticalLine(gridBottomLeft.X + ix * _Grid2DUnit, gridColor);
	}

	for (int iy = 0; iy < yGridCount; ++iy)
	{
		r.DrawFullHorizontalLine(gridBottomLeft.Y - iy * _Grid2DUnit, gridColor);
	}

	ScreenPoint worldOrigin = ScreenPoint::ToScreenCoordinate(_ScreenSize, -viewPos);
	r.DrawFullHorizontalLine(worldOrigin.Y, LinearColor::Red);
	r.DrawFullVerticalLine(worldOrigin.X, LinearColor::Green);
}

// 게임 오브젝트 목록


// 최초 씬 로딩을 담당하는 함수
void SoftRenderer::LoadScene2D()
{
	// 최초 씬 로딩에서 사용하는 모듈 내 주요 레퍼런스
	auto& g = Get2DGameEngine();

}

// [함수의 실행 순서와 변수 영역의 활용]
// 1. Update2D -> 변수 영역: 콘텐츠를 구성하는 물체의 최종 위치를 계산하고 이를 변수에 저장
// 2. 변수 영역 -> Render2D: 변수에 저장된 물체의 위치를 읽고, 이를 중심으로 물체를 화면에 그려냄

// 게임 로직과 렌더링 로직이 공유하는 변수
// 변수 영역: Update2D와 Render2D 함수에서 함께 공유할 변수를 선언한다.
// 벡터의 좌표를 관리할 변수를 currentPosition으로 선언한다.
// 물체의 위치를 보관하는 변수 currentPosition을 선언하고 기본 값은(100, 100)으로 지정한다.
Vector2 currentPosition;
// 최종 크기 값을 보관하는 변수 currentScale을 선언하고 기본 값을 10으로 지정한다.
float currentScale = 10.f;

// 게임 로직을 담당하는 함수
// Update2D 함수 영역: 입력에 따라 currentPosition 변수 값을 변화시킨다.
// 이 영역은 사용자 입력에 따라 물체를 이동시키는 게임 로직에 해당한다.
// 게임 로직을 담당하는 Update2D 함수를 구현한다.
// 게임 로직은 주로 사용자 입력에 따른 처리를 다룬다.
void SoftRenderer::Update2D(float InDeltaSeconds)
{
	// 게임 로직에서 사용하는 모듈 내 주요 레퍼런스
	// 게임 엔진 모듈에 접근한다.
	auto& g = Get2DGameEngine();
	// 게임 엔진 모듈에서 사용자 입력값을 읽어들일 수 있도록 입력 관리자 InputManager의 래퍼런스를 읽기 전용으로 가져온다.
	const InputManager& input = g.GetInputManager();

	// 게임 로직의 로컬 변수
	// 프레임당 이동 속도를 지정한다.
	static float moveSpeed = 100.f;
	// 최소 크기 값을 지정하는 변수 scaleMin을 선언한다.
	static float scaleMin = 5.f;
	// 최대 크기 값을 지정하는 변수 scaleMax를 선언한다.
	static float scaleMax = 20.f;
	// 애니메이션의 왕복 시간을 duration 변수로 지정한다.
	static float duration = 1.5f;
	// 현재 경과 시간을 보관하는 elapsedTime 변수를 선언한다.
	static float elapsedTime = 0.f;

	// X축과 Y축 입력을 결합해 입력 벡터를 생성한다.
	// GetNormalize() 함수를 사용해 입력 벡터의 크기를 항상 1로 정규화한다.
	Vector2 inputVector = Vector2(input.GetAxis(InputAxis::XAxis), input.GetAxis(InputAxis::YAxis)).GetNormalize();
	// 이동 속도와 프레임의 경과 시간 InDeltaTime을 곱하여 해당 프레임에서 이동할 길이를 계산한 후 이를 입력 벡터에 곱하고 그 결과를 변수 deltaPosition에 저장한다.
	Vector2 deltaPosition = inputVector * moveSpeed * InDeltaSeconds;

	// 경과 시간과 sin 함수를 활용한 [0, 1] 값의 생성
	// 프레임당 경과 시간을 elapsedTime에 더해 현재 경과 시간을 갱신한다.
	elapsedTime += InDeltaSeconds;
	// 나머지 값을 계산하는 Mod 함수를 사용해 현재 경과 시간이 duration 값을 넘으면 0으로 초기화하고 다시 계산한다.
	elapsedTime = Math::FMod(elapsedTime, duration);
	// 현재 시간에 대응되는 각을 계산한다.
	// sin 함수의 값은 [-1, 1] 범위를 가지는데, 선형 보간을 위해 [0, 1] 범위에 대응되도록 sin 함수에 1을 더하고 0.5를 곱한 후 이 값을 변수 alpha에 저장한다.
	// 변수 alpha 값은 시간에 따라 [0, 1] 범위를 왕복하게 된다.
	float currentRad = (elapsedTime / duration) * Math::TwoPI;
	float alpha = (sinf(currentRad) + 1) * 0.5f;

	// 물체의 최종 상태 설정
	// deltaPosition 값을 반영해 현재 프레임의 currentPosition 값을 확장한다.
	currentPosition += deltaPosition;
	// 선형 보간 함수 Lerp의 세 번째 인자에 0을 대입하면 최솟값 scaleMin을 얻고 1을 대입하면 최댓값 scaleMax 값이 얻어지며 중간값 0.5를 대입하면 최솟값과 최댓값의 중간값을 얻게 된다.
	// 변수 alpha 값은 시간에 따라 [0, 1] 범위를 왕복하므로 시간에 따라 최솟값과 최댓값 사이를 왕복하는 크기 값을 얻게 된다.
	currentScale = Math::Lerp(scaleMin, scaleMax, alpha);
}

// 렌더링 로직을 담당하는 함수
// Render2D 함수 영역: 입력을 반영해 최종 좌표를 저장한 currentPosition 변수 값을 읽어 해당 좌표에 지정한 색상으로 점을 찍고 선을 그린다.
// 이 영역은 화면에 그리는 기능을 수행하는 렌더링 로직에 해당한다.
// 렌더링 로직을 담당하는 Render2D 함수를 구현한다.
// 렌더링 로직은 게임 로직에서 계산한 데이터를 반영해 최종 결과를 모니터 화면에 보여주는 기능을 구현한다.
void SoftRenderer::Render2D()
{
	// 렌더링 로직에서 사용하는 모듈 내 주요 레퍼런스
	// 화면의 시각적 표현을 위해 렌더러 모듈의 래퍼런스를 가져온다.
	auto& r = GetRenderer();
	// 게임 엔진 모듈의 래퍼런스를 읽기 전용으로 가져온다.
	const auto& g = Get2DGameEngine();

	// 배경에 격자 그리기
	DrawGizmo2D();

	// 렌더링 로직의 로컬 변수
	// 현재 각을 지정하는 변수 rad를 선언한다.
	float rad = 0.f;
	// 각을 서서히 증가시키도록 증분값 increment를 선언한다.
	static float increment = 0.001f;
	// 하트를 구성하는 점을 모아둘 컨테이너 hearts를 선언한다.
	static std::vector<Vector2> hearts;
	// HSV 모델을 따르는 각 0에 대응하는 최초 색상을 지정한다. 명도 값은 조금 낮춘 0.85로 설정한다.
	HSVColor hsv(0.f, 1.f, 0.85f);

	// 하트를 구성하는 점 생성
	if (hearts.empty())
	{
		// 각을 0에서 2pi까지 서서히 증가시키는 루프를 생성한다.
		for (rad = 0.f; rad < Math::TwoPI; rad += increment)
		{
			// 하트 방정식을 사용해 해당 각의 x와 y값을 계산한다.
			float sin = sinf(rad);
			float cos = cosf(rad);
			float cos2 = cosf(2 * rad);
			float cos3 = cosf(3 * rad);
			float cos4 = cosf(4 * rad);
			float x = 16.f * sin * sin * sin;
			float y = 13 * cos - 5 * cos2 - 2 * cos3 - cos4;
			// x와 y값으로 벡터를 만든 후 이를 hearts에 추가한다.
			hearts.push_back(Vector2(x, y));
		}
	}

	// 각 값을 초기화한 후 색상을 증가시키면서 점에 대응
	// 변수 rad 값을 다시 0으로 초기화시킨다.
	rad = 0.f;
	for (auto const& v : hearts)
	{
		// 소프트웨어가 제공하는 HSV 모델의 H는 라디안 값이 아닌 [0, 1] 범위 값을 사용한다.
		// 따라서 원의 라디안 값에 해당하는 [0, 2pi] 범위를 [0, 1]의 범위로 변경한다.
		hsv.H = rad / Math::TwoPI;
		// HSV 색상을 RGB로 바꾼 후 점을 찍는다.
		r.DrawPoint(v * currentScale + currentPosition, hsv.ToLinearColor());
		// increment 변수를 사용해 각 rad 값을 증가시킨다.
		rad += increment;
	}

	// 현재 위치와 스케일을 화면에 출력
	r.PushStatisticText(std::string("Position : ") + currentPosition.ToString());
	r.PushStatisticText(std::string("Scale : ") + std::to_string(currentScale));

	// 3-2
	//// 그릴 원의 반지름을 50으로 지정한다.
	//static float radius = 50.f;
	//// 원을 구성하는 점을 보관하기 위한 자료구조로 vector를 선택하고 이를 circles로 선언한다.
	//// 이때 한번 생성한 변수는 계속 유지될 수 있도록 변수는 static으로 선언한다.
	//static std::vector<Vector2> circles;

	//// 최초에 한번 반지름보다 긴 벡터를 모아 컨테이너에 담는다.
	//// circles 자료구조가 비어 있는 경우에만 원을 구성하는 점을 채워 넣도록 조건을 지정한다.
	//if (circles.empty()) {
	//	// 반지름 정보를 활용해 원이 포함된 사각형 영역을 계산하고 이 안에 속한 벡터를 생성하기 위해 크기 1단위로 루프를 돈다.
	//	for (float x = -radius; x <= radius; ++x) {
	//		for (float y = -radius; y <= radius; ++y)
	//		{
	//			// x, y값을 결합해 벡터를 선언한다.
	//			Vector2 pointToTest = Vector2(x, y);
	//			// 벡터의 크기를 구할 때 제곱근을 씌우지 않은 값 x^2 + y^2만을 계산한다.
	//			float squardLength = pointToTest.SizeSquared();
	//			// squardLength 값과 크기를 비교하기 위해 반지름 값을 두 번 곱한다.
	//			// 이렇게 크기의 제곱값과 반지름의 제곱값을 비교하는 방법은 제곱근을 사용하지 않기 때문에 더 빠르게 결과를 얻어낸다.
	//			if (squardLength <= radius * radius)
	//			{
	//				// 위 조건문의 결과가 참이면 원을 구성하는 자료구조 circles에 해당 벡터를 추가한다.
	//				circles.push_back(Vector2(x, y));
	//			}
	//		}
	//	}
	//}

	//// 원을 구성하는 벡터를 모두 붉은색으로 표시한다.
	//// 원을 구성하는 자료구조 circles에 속한 모든 점을 순회한다.
	//for (auto const& v : circles) {
	//	// 각 점의 위치에 현재 중점 값을 더하고 붉은색으로 찍는다.
	//	r.DrawPoint(v + currentPosition, LinearColor::Red);
	//}

	// 3-1
	//// 밝은 회색의 선을 사용해 평행한 벡터를 표현
	//// 벡터 currentPosition과 평행한 벡터를 표현하도록 길이를 충분히 크게 지정한다.
	//static float lineLength = 500.f;
	//// 벡터 currentPosition과 평행한 선의 시작점과 끝점을 계산한다.
	//Vector2 lineStart = currentPosition * lineLength;
	//Vector2 lineEnd = currentPosition * -lineLength;
	//// 렌더러에서 제공하는 DrawLine 함수를 사용해 밝은 회색으로 평행한 선을 표현한다.
	//r.DrawLine(lineStart, lineEnd, LinearColor::LightGray);

	//// 벡터를 파란색 픽셀로 표현
	//// 파란색 점으로 벡터 currentPosition을 화면에 찍는다.
	//// 점이 잘 보이도록 해당 점의 둘레 8개 픽셀도 함께 찍는다.
	//r.DrawPoint(currentPosition, LinearColor::Blue);
	//r.DrawPoint(currentPosition + Vector2::UnitX, LinearColor::Blue);
	//r.DrawPoint(currentPosition - Vector2::UnitX, LinearColor::Blue);
	//r.DrawPoint(currentPosition + Vector2::UnitY, LinearColor::Blue);
	//r.DrawPoint(currentPosition - Vector2::UnitY, LinearColor::Blue);
	//r.DrawPoint(currentPosition + Vector2::One, LinearColor::Blue);
	//r.DrawPoint(currentPosition - Vector2::One, LinearColor::Blue);
	//r.DrawPoint(currentPosition + Vector2(1.f, -1.f), LinearColor::Blue);
	//r.DrawPoint(currentPosition - Vector2(1.f, -1.f), LinearColor::Blue);

	//// 벡터의 현재 좌표를 우상단에 출력
	//// 벡터 currentPosition의 좌표를 화면 우상단에 출력한다.
	//r.PushStatisticText("Coordinate : " + currentPosition.ToString());
}

// 메시를 그리는 함수
void SoftRenderer::DrawMesh2D(const class DD::Mesh& InMesh, const Matrix3x3& InMatrix, const LinearColor& InColor)
{
}

// 삼각형을 그리는 함수
void SoftRenderer::DrawTriangle2D(std::vector<DD::Vertex2D>& InVertices, const LinearColor& InColor, FillMode InFillMode)
{
}
