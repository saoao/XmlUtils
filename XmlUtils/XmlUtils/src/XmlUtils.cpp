#include "../inc/XmlUtils.h"
#include <qfile.h>
#include <QTextStream>
#include <QFileInfo>
#include <QDateTime>
#include <QLocale>

namespace Inter {
	static QString boolTostr(const bool in)
	{
		if (in)
		{
			return "true";
		}
		else
		{
			return "false";
		}
	}

	static bool strToBool(const QString & in)
	{
		if (0 == in.compare("true"))
		{
			return true;
		}
		return false;
	}

	/**
	 * ���ݽڵ�����ȡ�ڵ�
	 *
	 * \param [in]		rootEle  ���ڵ�.
	 * \param [in]		nodeName ����ѯ�Ľڵ���.
	 * \param [out]		node	 ���ҵ��Ľڵ�.
	 *
	 * \returns True if it succeeds, false if it fails.
	 */

	static bool getNodeByName(QDomElement & rootEle, const QString & nodeName, QDomElement & node)
	{
		if (nodeName == rootEle.tagName()) // ��Ϊ���ڵ㣬�򷵻�
		{
			node = rootEle;
			return true;
		}

		QDomElement ele = rootEle;  //���ظ�Ԫ��
		for (ele = rootEle.firstChildElement(); ele.isElement(); ele = ele.nextSiblingElement())
		{
			//�ݹ鴦���ӽڵ㣬��ȡ�ڵ�
			if (getNodeByName(ele, nodeName, node))
				return true;
		}
		//�����нڵ㶼�������������򷵻�false
		return false;
	}

	/**
	 * ����ƥ������ֵȥ��������Ӧ�ĵĽڵ㣬matchedContentӦ����Ψһ�ġ�
	 *
	 * \param [in]		rootEle  ���ڵ�.
	 * \param [in]		nodeName ����ѯ�Ľڵ���.
	 * \param [out]		node	 ���ҵ��Ľڵ�.
	 * \param [in]		matchedAttrName ��Ҫ����ƥ�����������.
	 * \param [in]		matchedContent  ��Ҫ����ƥ�������ֵ.
	 *
	 * \returns True if it succeeds, false if it fails.
	 */

	/*_rootEleΪ���ڵ㣬_nodeNameΪ����ѯ�Ľڵ�����_node��Ϊ���ҵ��Ľڵ�*/

	static bool getNodeByName(QDomElement & rootEle, const QString & nodeName, QDomElement & node,
		const QString &matchedAttrName, const QString & matchedContent)
	{
		if (nodeName == rootEle.tagName() && \
			rootEle.attribute(matchedAttrName).compare(matchedContent) == 0)
		{
			node = rootEle;
			return true;
		}
		QDomElement ele = rootEle;
		for (ele = rootEle.firstChildElement(); ele.isElement(); ele = ele.nextSiblingElement())
		{
			if (getNodeByName(ele, nodeName, node, matchedAttrName, matchedContent))
				return true;
		}
		return false;
	}

	const QString XML_FILE_CREATE_TIME_TAG = "createtime";
	const QString XML_FILE_LAST_MODIFIED_TIME_TAG = "lastmodifiedtime";
	const QString XML_FILE_VERSION_TAG = "fileversion";
	const QString VERSION_NUM = "1.0";
	const QString REQUIRED_VERSION_NUM = "1.0";
}

using namespace Inter;
 
QDomElement XmlUtils::addXmlNode(QDomDocument *domDocument,
	const QString & parentNodeName, 
	const QString & nodeName, 
	QStringList attrNames, 
	QStringList attrs, const QString &matchedAttrName, const QString & matchedContent)
{
	QDomElement rootEle = domDocument->documentElement();
	QDomElement parentNode;
	if (!getNodeByName(rootEle, parentNodeName, parentNode, matchedAttrName, matchedContent))
	{
		return QDomElement();
	}
	QDomElement newNode = domDocument->createElement(nodeName);
	if (attrNames.size() > 0)
	{
		for (int i = 0; i < attrNames.size(); ++i)
		{
			if (attrs.size() > 0)
			{
				newNode.setAttribute(attrNames[i], attrs[i]);
			}
			else
			{
				newNode.setAttribute(attrNames[i], "");
			}
		}
	}
	parentNode.appendChild(newNode);
	return newNode;
}

QDomElement XmlUtils::addXmlNode(QDomDocument * domDocument, 
	const QString & parentNodeName, const QString & nodeName,
	QStringList attrNames, QStringList attrs)
{
	QDomElement rootEle = domDocument->documentElement();
	QDomElement parentNode;
	if (!getNodeByName(rootEle, parentNodeName, parentNode))
	{
		return QDomElement();
	}
	QDomElement newNode = domDocument->createElement(nodeName);
	if (attrNames.size() > 0)
	{
		for (int i = 0; i < attrNames.size(); ++i)
		{
			if (attrs.size() > 0)
			{
				newNode.setAttribute(attrNames[i], attrs[i]);
			}
			else
			{
				newNode.setAttribute(attrNames[i], "");
			}
		}
	}
	parentNode.appendChild(newNode);
	return newNode;
}

QDomElement XmlUtils::addXmlNode(QDomDocument *domDocument, const QString & parentNodeName, const QString & nodeName, const QString & nodeText)
{
	QDomElement rootEle = domDocument->documentElement();  //���ظ�Ԫ��
	QDomElement parentNode;
	if (!getNodeByName(rootEle, parentNodeName, parentNode))
	{
		return QDomElement();
	}
	QDomElement newNode = domDocument->createElement(nodeName);
	QDomText text;
	text = domDocument->createTextNode(nodeText);
	newNode.appendChild(text);
	parentNode.appendChild(newNode);
	return newNode;
}

QDomElement XmlUtils::addXmlNode(QDomDocument * domDocument, const QString & parentNodeName, const QString & nodeName, const QString & nodeText,
	const QString &matchedNodeName, const QString & name)
{
	QDomElement rootEle = domDocument->documentElement();  //���ظ�Ԫ��
	QDomElement parentNode;
	if (!getNodeByName(rootEle, parentNodeName, parentNode, matchedNodeName, name))
	{
		return QDomElement();
	}
	QDomElement newNode = domDocument->createElement(nodeName);
	QDomText text;
	text = domDocument->createTextNode(nodeText);
	newNode.appendChild(text);
	parentNode.appendChild(newNode);
	return newNode;
}

void XmlUtils::addXmlNodeAttr(QDomDocument * domDocument, const QString & nodeName, 
	const QString &attrName, const QString &attr)
{
	QDomElement rootEle = domDocument->documentElement();
	QDomElement node;
	if (!getNodeByName(rootEle, nodeName, node))
	{
		return;
	}
	if (!attrName.isEmpty())
	{
		if (!attr.isEmpty())
		{
			node.setAttribute(attrName, attr);
		}
		else
		{
			node.setAttribute(attrName, "");
		}
	}
}

void XmlUtils::addXmlNodeText(QDomDocument * domDocument, const QString & nodeName, const QString & text)
{
	QDomElement rootEle = domDocument->documentElement();
	QDomElement node;
	if (!getNodeByName(rootEle, nodeName, node))
	{
		return;
	}
	if (!text.isEmpty())
	{
		appendText(domDocument, node, text);
	}
	else
	{
		appendText(domDocument, node, "");
	}
}

QDomElement XmlUtils::loadXMLDomDocument(QFile &rFile, QDomDocument *domDocument,
	const QString& rootTagName, QString &error)
{
	QString errorStr;
	int errorLine, errorColumn;
	/*�ж��Ƿ��������*/
	if (!domDocument->setContent(&rFile, false, &errorStr, &errorLine, &errorColumn)) //�����ĵ�����������
	{
		error.append(rFile.fileName() + QStringLiteral("->>ԭ�򣺴����޷����������� at line %1, column %2:\n%3\n")\
			.arg(errorLine)
			.arg(errorColumn)
			.arg(errorStr));
	}
	else
	{
		QDomElement xmlRoot = domDocument->documentElement();
		if (xmlRoot.tagName() != rootTagName)
		{
			error.append(rFile.fileName() + QStringLiteral("->>ԭ�򣺴���ĸ��ڵ��ǩ�� ") + \
				xmlRoot.tagName() + "!=" + rootTagName + "\n");
		}
		else
		{
			return xmlRoot;
		}
	}
	return QDomElement();
}

void XmlUtils::appendRootXMLProcessingInstruction(QDomDocument * domDocument)
{
	QDomNode xmlProcessingInstruction = domDocument->createProcessingInstruction("xml", "version=\"1.0\" encoding=\"UTF-8\"");
	domDocument->insertBefore(xmlProcessingInstruction, domDocument->firstChild());
}

QDomElement XmlUtils::appendRootElement(QDomDocument * domDocument, QString name, QString& createTime)
{
	QDomElement root = domDocument->createElement(name);
	domDocument->appendChild(root);
	createTime = generateCreateTime();
	root.setAttribute(XML_FILE_CREATE_TIME_TAG, createTime);
	root.setAttribute(XML_FILE_LAST_MODIFIED_TIME_TAG, createTime);
	root.setAttribute(XML_FILE_VERSION_TAG, VERSION_NUM);
	return root;
}

QDomElement XmlUtils::appendDomElement(QDomElement &rDomElement, const QString elementName)
{
	QDomElement subDomElement = rDomElement.ownerDocument().createElement(elementName);
	rDomElement.appendChild(subDomElement);
	return subDomElement;
}

QDomElement XmlUtils::getOrAppendNewDomElement(QDomElement &rDomElement, const QString elementName)
{
	QDomElement elem = rDomElement.firstChildElement(elementName);
	if (elem.isNull())
	{
		return appendDomElement(rDomElement, elementName);
	}
	else
	{
		return elem;
	}
}

QDomElement XmlUtils::appendDomTextNode(QDomElement &rDomElement, 
	const QString elementName, const QString text)
{
	//ֻ�������ƺ�ֵ����Ϊ��ʱ��дtag
	QDomElement subDomElement;
	if (!elementName.isEmpty() && !text.isEmpty())
	{
		QDomDocument ownerDomDocument = rDomElement.ownerDocument();
		subDomElement = ownerDomDocument.createElement(elementName);
		subDomElement.appendChild(ownerDomDocument.createTextNode(text));
		rDomElement.appendChild(subDomElement);
	}
	return subDomElement;
}

QDomElement XmlUtils::appendDomBooleanNode(QDomElement &rDomElement, const QString elementName, const bool value)
{
	if (value)
	{
		return appendDomTextNode(rDomElement, elementName, "TRUE_TAG");
	}
	else
	{
		return appendDomTextNode(rDomElement, elementName, "FALSE_TAG");
	}
}

QDomElement XmlUtils::appendDomIntegerNode(QDomElement &rDomElement, const QString elementName, const int val)
{
	QString tmp_string;
	tmp_string.setNum(val);
	return appendDomTextNode(rDomElement, elementName, tmp_string);
}

QDomElement XmlUtils::appendDomDoubleValueNode(QDomElement &rDomElement, const QString elementName, const double val, const char format, const int precision)
{
	return appendDomTextNode(rDomElement, elementName, QString("%1").arg(val, 0, format, precision));
}

QDomElement XmlUtils::appendDomDoubleValueNode2(QDomElement &rDomElement, const QString elementName, const double a, const double b, const char format, const int precision)
{
	return appendDomTextNode(rDomElement, elementName, QString("%1 %2").arg(a, 0, format, precision).arg(b, 0, format, precision));
}

QDomElement XmlUtils::appendDomDoubleValueNodeN(QDomElement &rDomElement, const QString elementName, const QVector<double> &rValues, const char format, const int precision)
{
	QString num, str;
	for (int i = 0; i < rValues.size(); ++i)
	{
		num.setNum(rValues[i], format, precision);
		str.append(num);
		str.append(" ");
	}
	str.chop(1); //Remove last space
	return appendDomTextNode(rDomElement, elementName, str);
}

void XmlUtils::setQrealAttribute(QDomElement domElement, const QString attrName, const double attrValue, const int precision, const char format)
{
	QString str;
	domElement.setAttribute(attrName, str.setNum(attrValue, format, precision));
}

void XmlUtils::parseDomDoubleValueNode3(QDomElement &domElement, double &rA, double &rB, double &rC)
{
	QStringList poseList = domElement.text().split(" ");
	rA = poseList[0].toDouble();
	rB = poseList[1].toDouble();
	rC = poseList[2].toDouble();
}

void XmlUtils::parseDomDoubleValueNode2(QDomElement &domElement, double &rA, double &rB)
{
	QStringList poseList = domElement.text().split(" ");
	if (poseList.size() < 2) return;
	rA = poseList[0].toDouble();
	rB = poseList[1].toDouble();
}

double XmlUtils::parseDomDoubleValueNode(QDomElement &domElement, const double defaultValue)
{
	if (!domElement.isNull())
	{
		bool isOk;
		double val = domElement.text().toDouble(&isOk);
		if (isOk)
		{
			return val;
		}
	}
	// ���domΪ�գ����߽���ʧ�ܣ��򷵻�Ĭ��ֵ
	return defaultValue;
}

int XmlUtils::parseDomIntegerNode(QDomElement &domElement, const int defaultValue)
{
	if (!domElement.isNull())
	{
		bool isOk;
		int val = domElement.text().toInt(&isOk);
		if (isOk)
		{
			return val;
		}
	}
	//���domΪ�գ����߽���ʧ�ܣ��򷵻�Ĭ��ֵ
	return defaultValue;
}

bool XmlUtils::parseDomBooleanNode(QDomElement &domElement, const bool defaultValue)
{
	// ���domԪ��Ϊ�գ��򷵻�Ĭ��ֵ
	if (domElement.isNull())
	{
		return defaultValue;
	}
	// else������Ƿ�Ϊ��(something else = false)
	return (domElement.text() == "TRUE_TAG");
}

bool XmlUtils::parseAttributeBool(const QDomElement &domElement, const QString attributeName, const bool defaultValue)
{
	QString attr = domElement.attribute(attributeName, boolTostr(defaultValue));
	if ((attr == "true") || (attr == "True") || (attr == "1"))
	{
		return true;
	}

	return false;
}

void XmlUtils::parseSimulationTimeTag(QDomElement &domElement, QString &rStart, QString &rStep, QString &rStop, bool &rInheritTs)
{
	rStart = domElement.attribute("start");
	rStep = domElement.attribute("timestep");
	rStop = domElement.attribute("stop");
	rInheritTs = parseAttributeBool(domElement, "inherit_timestep", true);
}

QString XmlUtils::parseDomTextNode(QDomElement domElement, const QString &rDefaultValue)
{
	if (!domElement.isNull())
	{
		return domElement.text();
	}
	return rDefaultValue;
}

//��ע��
QDomComment XmlUtils::appendComment(QDomElement &rDomElement, const QString &rComment)
{
	QDomComment xmlcomment = rDomElement.ownerDocument().createComment(rComment);
	rDomElement.appendChild(xmlcomment);
	return xmlcomment;
}

QDomElement XmlUtils::addOneNilNode(QDomDocument * dom, 
	const QString & _parentNodeName, const QString & _nodeName)
{
	QDomElement rootEle = dom->documentElement();  //���ظ�Ԫ��
	QDomElement parentNode;
	if (!getNodeByName(rootEle, _parentNodeName, parentNode))
	{
		return QDomElement();
	}
	QDomElement newNode = dom->createElement(_nodeName);
	parentNode.appendChild(newNode);
	return newNode;
}

QDomElement XmlUtils::addOneNilNode(QDomDocument * dom,
	const QString & _parentNodeName, 
	const QString & _nodeName, 
	const QString & matchedAttrName, 
	const QString & matchedContent)
{
	QDomElement rootEle = dom->documentElement();  //���ظ�Ԫ��
	QDomElement parentNode;
	if (!getNodeByName(rootEle, _parentNodeName, parentNode, matchedAttrName, matchedContent))
	{
		return QDomElement();
	}
	QDomElement newNode = dom->createElement(_nodeName);
	parentNode.appendChild(newNode);
	return newNode;
}

bool XmlUtils::deleteNode(QDomDocument *dom, const QString & _nodeName)
{
	QDomElement rootEle = dom->documentElement();
	QDomElement node;
	if (!getNodeByName(rootEle, _nodeName, node))
	{
		return false;
	}
	if (rootEle == node)
	{
		return false;
	}
	if (node.isElement())
	{
		QDomNode parentEle = node.parentNode();
		if (parentEle.isElement())
			parentEle.removeChild(node);
		else
			return false;
	}
	return true;
}

bool XmlUtils::deleteNode(QDomDocument * dom, const QString & _nodeName, 
	const QString &matchedAttrName, const QString & matchedContent)
{
	QDomElement rootEle = dom->documentElement();
	QDomElement node;
	if (!getNodeByName(rootEle, _nodeName, node, matchedAttrName, matchedContent))
	{
		return false;
	}

	if (rootEle == node)
	{
		return false;
	}
	if (node.isElement())
	{
		QDomNode parentEle = node.parentNode();
		if (parentEle.isElement())
			parentEle.removeChild(node);
		else
			return false;
	}
	return true;
}

bool XmlUtils::deleteNodeAttr(QDomDocument * dom, const QString & nodeName, QString attrName)
{
	QDomElement rootEle = dom->documentElement();
	QDomElement node;
	if (!getNodeByName(rootEle, nodeName, node))
	{
		return false;
	}
	if (rootEle == node)
	{
		return false;
	}
	if (node.isElement())
	{
		if (node.hasAttribute(attrName))
		{
			node.removeAttribute(attrName);
		}
	}
	return true;
}

//�޸�һ��ָ��Ԫ�ص�����
bool XmlUtils::modifiedContent(QDomDocument *dom, const QString & nodeName, const QString &newText)
{
	QDomElement rootEle = dom->documentElement();
	QDomElement node;
	if (!getNodeByName(rootEle, nodeName, node))
	{
		return false;
	}
	if (node.isElement())
	{
		if (node.text().isEmpty()) {
			appendText(dom, node, newText);
			return true;
		}
		QDomNode oldnode = node.firstChild();     //��ǩ֮���������Ϊ�ڵ���ӽڵ���֣��õ�ԭ�����ӽڵ�
		node.firstChild().setNodeValue(newText);  //���ṩ��valueֵ�������ӽڵ������
		QDomNode newnode = node.firstChild();     //ֵ�޸Ĺ���
		node.replaceChild(newnode, oldnode);      //���ýڵ��replaceChild����ʵ���޸Ĺ���
	}
	return true;
}

bool XmlUtils::modifiedContent(QDomDocument * dom, const QString & nodeName,
	const QString& attrName, const QString& newAttr)
{
	QDomElement rootEle = dom->documentElement();
	QDomElement node;
	if (!getNodeByName(rootEle, nodeName, node))
	{
		return false;
	}
	if (node.isElement())
	{
		if (node.hasAttribute(attrName))
		{
			node.removeAttribute(attrName);
			node.setAttribute(attrName, newAttr);
		}
	}
	return true;
}

bool XmlUtils::modifiedContent(QDomDocument * rDomDocument, const QString & nodeName,
	const QString & matchedAttrName, const QString & matchedContent,
	const QString & attrName, const QString & newAttr)
{
	QDomElement rootEle = rDomDocument->documentElement();
	QDomElement node;
	if (!getNodeByName(rootEle, nodeName, node, matchedAttrName, matchedContent))
	{
		return false;
	}
	if (node.isElement())
	{
		if (node.hasAttribute(attrName))
		{
			node.removeAttribute(attrName);
			node.setAttribute(attrName, newAttr);
		}
	}
	return true;
}

QDomText XmlUtils::appendText(QDomDocument *rDomDocument, QDomElement & rDomElement, const QString & rText)
{
	QDomText text = rDomDocument->createTextNode(rText);
	rDomElement.appendChild(text);
	return QDomText();
}

bool XmlUtils::verifyProjectFileVersion(const QString & version)
{
	return (version >= REQUIRED_VERSION_NUM);
}

bool XmlUtils::verifySolutionFileVersion(const QString & version)
{
	return (version >= VERSION_NUM);
}

const QString XmlUtils::generateCreateTime()
{
	QLocale locale = QLocale::English;
	QString strFormat = "yyyy/MM/dd hh:mm:ss.zzz";
	QDateTime dateTime = QDateTime::currentDateTime();
	QString strDateTime = locale.toString(dateTime, strFormat);
	return strDateTime;
}

bool XmlUtils::saveDom(QDomDocument* dom, const QString& savePath)
{
	QFile file(savePath);
	if (!file.open(QIODevice::WriteOnly))
	{
		return false;
	}
	QTextStream out(&file);
	dom->save(out, 4);
	file.close();
	return false;
}

