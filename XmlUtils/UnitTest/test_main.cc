#include <QtCore/QCoreApplication>
#include "test_XmlUtils.h"

class QtAppEnvironment : public testing::Environment
{
public:
	QtAppEnvironment(int argc, char ** argv)
		:m_argc(argc),
		m_argv(argv) {
	}

	virtual void SetUp() {
		m_app = new QCoreApplication(m_argc, m_argv);
	}

	virtual void TearDown() {
		m_app->exec();
	}

private:
	QCoreApplication *m_app;
	int m_argc;
	char **m_argv;
};

int main(int argc, char ** argv) {
	testing::AddGlobalTestEnvironment(new QtAppEnvironment(argc, argv));
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
