// Navigation pane project template
#include "Bbmoviez.hpp"

#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/AbstractPane>
#include <bb/cascades/NavigationPane>
#include <bb/cascades/Page>
#include <bb/cascades/Container>
#include <bb/cascades/AbsoluteLayout>
#include <bb/cascades/AbsoluteLayoutProperties>
#include "SearchController.h"
#include "RESTClient.hpp"

#include <../Box2D/Box2D.h>

#include <cstdio>
using namespace std;

using namespace bb::cascades;

Bbmoviez::Bbmoviez(bb::cascades::Application *app) :
		QObject(app),
		m_nodePane(0){
	// create scene document from main.qml asset
	// set parent to created document to ensure it exists for the whole application lifetime
	QmlDocument *qml = QmlDocument::create("asset:///main.qml").parent(this);
	qml->setContextProperty("_controller", this);
	m_root = qml;
	// create root object for the UI
	m_rootPane = qml->createRootObject<AbstractPane>();
	// set created root object as a scene
	app->setScene(m_rootPane);
	initializeControllers();
	QObject::connect(RESTClient::getInstance(), SIGNAL(downloadCompleted(QString)),
				SLOT(doStuff(QString)));
	//RESTClient::getInstance()->requestJson();
}

void Bbmoviez::initializeControllers() {
	Controller* controller;
	controller = new SearchController(m_root);
	m_root->setContextProperty("_searchController", controller);
	connect(controller, SIGNAL(moviePicked()), SLOT(showNodePage()));
}

void Bbmoviez::doStuff(QString s)
{
	qDebug() << s;
}

void Bbmoviez::showNodePage(){
	if(m_nodePane)
	{
		delete m_nodePane;
		m_containerList.clear();
	}
	m_nodePane = Page::create().
			content(Container::create().
					preferredSize(768, 1280).
					layout(new AbsoluteLayout()));

	qobject_cast<NavigationPane*>(m_rootPane)->push(m_nodePane);
	physics();
}

enum {
	e_count = 20
};

void Bbmoviez::physics () {

	b2Body* m_bodies[e_count];

	// Define the gravity vector.
	b2Vec2 gravity(0.0f, -10.0f);

	// Construct a world object, which will hold and simulate the rigid bodies.
	b2World m_world(gravity);

	b2BodyDef bd;
	b2Body* ground = m_world.CreateBody(&bd);
	{
		b2EdgeShape shape;
		shape.Set(b2Vec2(-15.0f, -5.3f), b2Vec2(15.5f, -5.3f));
		ground->CreateFixture(&shape, 0.0f);
		shape.Set(b2Vec2(-15.0f, 80.0f), b2Vec2(15.5f, 80.0f));
		ground->CreateFixture(&shape, 0.0f);
		shape.Set(b2Vec2(-15.0f, -5.3f), b2Vec2(-15.0f, 80.0f));
		ground->CreateFixture(&shape, 0.0f);
		shape.Set(b2Vec2(15.5f, -5.3f), b2Vec2(15.5f, 80.0f));
		ground->CreateFixture(&shape, 0.0f);
	}

	// Define another box shape for our dynamic body.
	b2CircleShape shape;
	// Define the dynamic body fixture.
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &shape;

	// Set the box density to be non-zero, so it will be dynamic.
	fixtureDef.density = 1.0f;

	// Override the default friction.
	fixtureDef.friction = 0.3f;
	float r, x, y;
	float from[2], to[2];
	AbsoluteLayoutProperties* pProperties = AbsoluteLayoutProperties::create();
	for (int32 i = 0; i < e_count; ++i) {
		b2BodyDef bd;
		bd.type = b2_dynamicBody;
		shape.m_radius = rand() % 6 * 1.0f + 1;
		from[0] = to[0] = 0;
		from[1] = 6; to[1] = 768/2;
		float cs = convertToRange(shape.m_radius, from, to);
		QmlDocument *qml = QmlDocument::create("asset:///controls/Node.qml");
		Container* c = qml->createRootObject<Container>();
		m_containerList.append(c);
		c->setPreferredSize(cs, cs);
		qobject_cast<Container*>(m_nodePane->content())->add(c);
		x=r * (r < 3 ? -1 : 1);
		bd.position.Set(x, 70.0f);
		from[0] = -15; from[1] = 15.5;
		to[0] = 0; to[1] = 768;
		pProperties->setPositionX(convertToRange(x, from, to));
		pProperties->setPositionY(0);
		c->setLayoutProperties(pProperties);

		m_bodies[i] = m_world.CreateBody(&bd);

		m_bodies[i]->CreateFixture(&fixtureDef);

		m_bodies[i]->SetLinearVelocity(b2Vec2(0.0f, 0.0f));
	}


	// Prepare for simulation. Typically we use a time step of 1/60 of a
	// second (60Hz) and 10 iterations. This provides a high quality simulation
	// in most game scenarios.
	float32 timeStep = 1.0f / 60.0f;
	int32 velocityIterations = 6;
	int32 positionIterations = 2;

	// This is our little game loop.
	for (int32 i = 0; i < 60 * 3; ++i) {
		// Instruct the world to perform a single step of simulation.
		// It is generally best to keep the time step and iterations fixed.
		m_world.Step(timeStep, velocityIterations, positionIterations);

		for (int32 j = 0; j < e_count; ++j) {
			// Now print the position and angle of the body.
			b2Vec2 position = m_bodies[j]->GetPosition();
			float32 angle = m_bodies[j]->GetAngle();
			//printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);
			from[0] = -15; from[1] = 15.5;
			to[0] = 0; to[1] = 768;
			pProperties->setPositionX(convertToRange(position.x, from, to));
			from[0] = -5.3; from[1] = 80;
			to[0] = 0; to[1] = 1280;
			pProperties->setPositionY(convertToRange(position.y, from, to));
			m_containerList[j]->setLayoutProperties(pProperties);
		}
	}
	delete pProperties;

	// When the world destructor is called, all bodies and joints are freed. This can
	// create orphaned pointers, so be careful about your world management.

	return;
}

float Bbmoviez::convertToRange(float value, float* srcRange, float* dstRange){
  // value is outside source range return
  if (value < srcRange[0] || value > srcRange[1]){
    return 0;
  }

  float srcMax = srcRange[1] - srcRange[0],
      dstMax = dstRange[1] - dstRange[0],
      adjValue = value - srcRange[0];

  return (adjValue * dstMax / srcMax) + dstRange[0];
}


