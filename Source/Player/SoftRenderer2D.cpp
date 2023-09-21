
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
Vector2 currentPosition(100.f, 100.f);

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

	// X축과 Y축 입력을 결합해 입력 벡터를 생성한다.
	Vector2 inputVector = Vector2(input.GetAxis(InputAxis::XAxis), input.GetAxis(InputAxis::YAxis));
	// 이동 속도와 프레임의 경과 시간 InDeltaTime을 곱하여 해당 프레임에서 이동할 길이를 계산한 후 이를 입력 벡터에 곱하고 그 결과를 변수 deltaPosition에 저장한다.
	Vector2 deltaPosition = inputVector * moveSpeed * InDeltaSeconds;

	// 물체의 최종 상태 설정
	// deltaPosition 값을 반영해 현재 프레임의 currentPosition 값을 확장한다.
	currentPosition += deltaPosition;
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


	// 밝은 회색의 선을 사용해 평행한 벡터를 표현
	// 벡터 currentPosition과 평행한 벡터를 표현하도록 길이를 충분히 크게 지정한다.
	static float lineLength = 500.f;
	// 벡터 currentPosition과 평행한 선의 시작점과 끝점을 계산한다.
	Vector2 lineStart = currentPosition * lineLength;
	Vector2 lineEnd = currentPosition * -lineLength;
	// 렌더러에서 제공하는 DrawLine 함수를 사용해 밝은 회색으로 평행한 선을 표현한다.
	r.DrawLine(lineStart, lineEnd, LinearColor::LightGray);

	// 벡터를 파란색 픽셀로 표현
	// 파란색 점으로 벡터 currentPosition을 화면에 찍는다.
	// 점이 잘 보이도록 해당 점의 둘레 8개 픽셀도 함께 찍는다.
	r.DrawPoint(currentPosition, LinearColor::Blue);
	r.DrawPoint(currentPosition + Vector2::UnitX, LinearColor::Blue);
	r.DrawPoint(currentPosition - Vector2::UnitX, LinearColor::Blue);
	r.DrawPoint(currentPosition + Vector2::UnitY, LinearColor::Blue);
	r.DrawPoint(currentPosition - Vector2::UnitY, LinearColor::Blue);
	r.DrawPoint(currentPosition + Vector2::One, LinearColor::Blue);
	r.DrawPoint(currentPosition - Vector2::One, LinearColor::Blue);
	r.DrawPoint(currentPosition + Vector2(1.f, -1.f), LinearColor::Blue);
	r.DrawPoint(currentPosition - Vector2(1.f, -1.f), LinearColor::Blue);

	// 벡터의 현재 좌표를 우상단에 출력
	// 벡터 currentPosition의 좌표를 화면 우상단에 출력한다.
	r.PushStatisticText("Coordinate : " + currentPosition.ToString());
}

// 메시를 그리는 함수
void SoftRenderer::DrawMesh2D(const class DD::Mesh& InMesh, const Matrix3x3& InMatrix, const LinearColor& InColor)
{
}

// 삼각형을 그리는 함수
void SoftRenderer::DrawTriangle2D(std::vector<DD::Vertex2D>& InVertices, const LinearColor& InColor, FillMode InFillMode)
{
}
