package lego

import (
	uuid "github.com/satori/go.uuid"
)

// Question data struct
type Question struct {
	ID           string
	Title        string
	ResponseType int
	Description  string
	Order        int
}

// Page data struct
type Page struct {
	ID        string
	Title     string
	Order     int
	Questions []*Question
}

// Template data struct
type Template struct {
	ID    string
	Name  string
	Pages []*Page
}

// DataGenerator type
type DataGenerator struct {
}

// DataGen is instance of DataGenerator
var DataGen *DataGenerator

func init() {
	DataGen = &DataGenerator{}
}

// GenerateData generates template data
func (g *DataGenerator) GenerateData() *Template {
	var pages []*Page
	for j := 0; j < 10; j++ {
		var questions []*Question

		for i := 0; i < 20; i++ {
			question := &Question{
				ID:           uuid.NewV4().String(),
				Title:        "Question title",
				ResponseType: 3,
				Description:  "This is the description for the question. This is the description for the question. This is the description for the question. This is the description for the question.",
				Order:        i,
			}
			questions = append(questions, question)
		}

		page := &Page{
			ID:        uuid.NewV4().String(),
			Title:     "Page title",
			Order:     j,
			Questions: questions,
		}
		pages = append(pages, page)
	}

	return &Template{
		ID:    uuid.NewV4().String(),
		Name:  "Template name",
		Pages: pages,
	}
}
